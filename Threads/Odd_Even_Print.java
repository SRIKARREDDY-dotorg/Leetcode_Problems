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

// Printing ABC with three threads

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

// Odd–Even Printer
class Main {
    public static void main(String[] args) {
        int n = 10;
        PrintABC printer = new PrintABC(n);
        
        Thread t1 = new Thread(printer::printA, "Thread A");
        Thread t2 = new Thread(printer::printB, "Thread B");
        Thread t3 = new Thread(printer::printC, "Thread C");
        
        t1.start();
        t2.start();
        t3.start();
    }
}

class PrintABC {
    private final int n;
    private final Lock lock = new ReentrantLock();
    private final Condition condA = lock.newCondition();
    private final Condition condB = lock.newCondition();
    private final Condition condC = lock.newCondition();
    private int state = 0;
    
    public PrintABC(int n) {
        this.n = n;
    }
    
    public void printA() {
        for(int i = 0; i < n; i ++) {
            lock.lock();
            try {
                while(state != 0) {
                    condA.await();
                }
                System.out.println("A");
                state = 1;
                condB.signal();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            } finally {
                lock.unlock();
            }
        }
    }
    
    public void printB() {
        for(int i = 0; i < n; i ++) {
            lock.lock();
            try {
                while(state != 1) {
                    condB.await();
                }
                System.out.println("B");
                state = 2;
                condC.signal();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            } finally {
                lock.unlock();
            }
        }
    }
    
    public void printC() {
        for(int i = 0; i < n; i ++) {
            lock.lock();
            try {
                while(state != 2) {
                    condC.await();
                }
                System.out.println("C");
                System.out.println("------------------------------");
                state = 0;
                condA.signal();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            } finally {
                lock.unlock();
            }
        }
    }
}

