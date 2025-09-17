
import java.util.concurrent.Semaphore;

class DiningPhilosophers {
    public static void main(String[] args) {
        int numPhilosophers = 5;
        Philosopher[] philosophers = new Philosopher[numPhilosophers];
        Object[] forks = new Object[numPhilosophers];
        
        for (int i = 0; i < numPhilosophers; i ++) {
            forks[i] = new Object();
        }
        
        for (int i = 0; i < numPhilosophers; i++) {
            Object leftFork = forks[i];
            Object rightFork = forks[(i + 1) % numPhilosophers]; // wrap around for last philosopher

            philosophers[i] = new Philosopher(leftFork, rightFork, i);
            new Thread(philosophers[i], "Philosopher " + i).start();
        }
    }
}

class Philosopher implements Runnable {
    private final Object leftFork;
    private final Object rightFork;
    private final int id;
    private static final Semaphore table = new Semaphore(4);
    
    public Philosopher(Object leftFork, Object rightFork, int id) {
        this.leftFork = leftFork;
        this.rightFork = rightFork;
        this.id = id;
    }
    
    @Override
    public void run() {
        try {
            while(true) {
                think();
                table.acquire();
                eat();
                table.release();
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
    
    private void think() throws InterruptedException {
        System.out.println("Philosopher " + id + " is thinking...");
        Thread.sleep((int) (Math.random() * 1000));
    }
    
    private void eat() throws InterruptedException {
        synchronized (leftFork) {
            System.out.println("Philosopher " + id + " picked up left fork");
            synchronized (rightFork) {
                System.out.println("Philosopher " + id + " picked up right fork and start eating");
                Thread.sleep((int) (Math.random() * 1000));
                System.out.println("Philosopher " + id + " put down right fork");
            }
            System.out.println("Philosopher " + id + " put down left fork");
        }
    }
}
