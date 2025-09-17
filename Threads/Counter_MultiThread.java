import java.util.concurrent.atomic.AtomicInteger;
class RaceConditionDemo {
    private static AtomicInteger counter = new AtomicInteger(0);
    public static void main(String[] args) throws InterruptedException {
        int numThreads = 5;
        int incrementsPerThread = 1000;
        Thread[] threads = new Thread[numThreads];
        for (int i = 0; i < numThreads; i++) {
            threads[i] = new Thread(() - > {
                for (int j = 0; j < incrementsPerThread; j++) {
                    counter.incrementAndGet();
                }
            });
            threads[i].start();
        }
        for (Thread t: threads) {
            t.join();
        }
        System.out.println("Final Counter value: " + counter);
        System.out.println("Expected value: " + numThreads * incrementsPerThread);
    }
}
