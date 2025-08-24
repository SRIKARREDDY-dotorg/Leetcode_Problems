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

// Mofified version with Reentrant and condition

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

// Odd–Even Printer
class Main {
    public static void main(String[] args) {
        int n = 10;
        PrintNumbers printer = new PrintNumbers(n);
        
        Thread oddThread = new Thread(printer::printOdd, "Odd Thread");
        Thread evenThread = new Thread(printer::printEven, "Even Thread");
        
        oddThread.start();
        evenThread.start();
    }
}

class PrintNumbers {
    public int number = 1;
    private final int n;
    private final Lock lock = new ReentrantLock();
    private final Condition oddTurn = lock.newCondition();
    private final Condition evenTurn = lock.newCondition();
    
    public PrintNumbers(int n) {
        this.n = n;
    }
    
    public void printOdd() {
        while(true) {
            try {
                lock.lock();
                while(number <= n && number%2 == 0) {
                    oddTurn.await();
                }
                if(number > n) {
                    evenTurn.signal();
                    break;
                }
                System.out.println(Thread.currentThread().getName() + ": " + number);
                number++;
                evenTurn.signal();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            } finally {
                lock.unlock();
            }
        }
    }
    
    public void printEven() {
        while(true) {
            try {
                lock.lock();
                while(number <= n && number%2 != 0) {
                    evenTurn.await();
                }
                if(number > n) {
                    oddTurn.signal();
                    break;
                }
                System.out.println(Thread.currentThread().getName() + ": " + number);
                number++;
                oddTurn.signal();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            } finally {
                lock.unlock();
            }
        }
    }
}


