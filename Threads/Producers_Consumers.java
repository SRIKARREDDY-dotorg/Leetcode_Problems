import java.util.LinkedList;
import java.util.Queue;

// Producer consumer with Bounded buffer
class Main {
    public static void main(String[] args) {
        int n = 10;
        BoundedBlockingQueue<Integer> queue = new BoundedBlockingQueue<>(5);
        // Multiple producers
        Runnable producer = () -> {
            try {
                for(int i = 0; i < 20; i ++) {
                    queue.enqueue(i);
                    Thread.sleep(100);
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        };
        
        Runnable consumer = () -> {
            try {
                for(int i = 0; i < 20; i ++) {
                    queue.dequeue();
                    Thread.sleep(200);
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        };
        
        new Thread(producer, "Producer-1").start();
        new Thread(producer, "Producer-2").start();
        new Thread(consumer, "Consumer-1").start();
        new Thread(consumer, "Consumer-2").start();
     }
}

class BoundedBlockingQueue<T> {
    private final Queue<T> queue = new LinkedList<>();
    private final int capacity;
    private final Object lock = new Object();
    
    public BoundedBlockingQueue(int capacity) {
        this.capacity = capacity;
    }
    
    public void enqueue(T item) throws InterruptedException {
        synchronized (lock) {
            // wait if queue is full
            while(queue.size() == capacity) {
                lock.wait();
            }
            queue.add(item);
            System.out.println(Thread.currentThread().getName() + " enqueued: " + item);
            lock.notifyAll();
        }
    }
    
    public T dequeue() throws InterruptedException {
        synchronized (lock) {
            while(queue.isEmpty()) {
                lock.wait();
            }
            
            T item = queue.remove();
            System.out.println(Thread.currentThread().getName() + " dequeued: " + item);
            lock.notifyAll();
            return item;
        }
    }
}
