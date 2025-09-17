import java.util.concurrent.locks.ReentrantReadWriteLock;

class ReaderWriterDemo {
    public static void main(String[] args) {
        SharedResource resource = new SharedResource();
        
        // Start multiple readers
        for (int i = 1; i <= 3; i ++) {
            int readerId = i;
            new Thread(() -> {
                while (true) {
                    resource.read(readerId);
                }
            }).start();
        }
        
        // Start multiple writers
        for (int i = 1; i <= 2; i ++) {
            int writerId = i;
            new Thread(() -> {
                int value = 0;
                while (true) {
                    resource.write(writerId, value++);
                }
            }).start();
        }
    }
}

class SharedResource {
    private int data = 0;
    private final ReentrantReadWriteLock rwLock = new ReentrantReadWriteLock();
    
    public void read(int readerId) {
        rwLock.readLock().lock();
        
        try {
            System.out.println("Reader " + readerId + " reads data: " + data);
            Thread.sleep(100); // simulate reading
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        } finally {
            rwLock.readLock().unlock();
        }
    }
    
    public void write(int writerId, int value) {
        rwLock.writeLock().lock();
        
        try {
            System.out.println("Writer " + writerId + "writes data: " + value);
            data = value;
            Thread.sleep(150);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        } finally {
            rwLock.writeLock().unlock();
        }
    }
}
