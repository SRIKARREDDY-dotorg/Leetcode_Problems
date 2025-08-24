// Odd–Even Printer
class Main {
    public static void main(String[] args) {
        int n = 10;
        PrintNumbers sharedObject = new PrintNumbers(n);
        
        Thread oddThread = new Thread(() -> {
            try {
                sharedObject.printOdd();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }, "Odd thread");
        
        Thread evenThread = new Thread(() -> {
            try {
                sharedObject.printEven();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }, "Even thread");
        
        oddThread.start();
        evenThread.start();
    }
}

class PrintNumbers {
    public int number = 1;
    private final int n;
    private final Object lock = new Object();
    
    public PrintNumbers(int n) {
        this.n = n;
    }
    
    public void printOdd() throws InterruptedException {
        synchronized (lock) {
            while (number <= n) {
                if (number % 2 == 0) {
                    lock.wait();
                } else {
                    System.out.println(Thread.currentThread().getName() + ": " + number);
                    number++;
                    lock.notify();
                }
            }
        }
    }
    
    public void printEven() throws InterruptedException {
        synchronized (lock) {
            while (number <= n) {
                if (number % 2 != 0) {
                    lock.wait();
                } else {
                    System.out.println(Thread.currentThread().getName() + ": " + number);
                    number++;
                    lock.notify();
                }
            }
        }
    }
}
