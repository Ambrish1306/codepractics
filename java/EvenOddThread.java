
public class EvenOddThread {
    static int current = 1;
    static final Object lock = new Object();

    static class EvenRunnable implements Runnable {
        @Override
        public void run() {
            synchronized (lock) {
                while (current <= 10) {
                    while (current % 2 != 0) {
                        try {
                            lock.wait();
                        } catch (InterruptedException e) {
                            Thread.currentThread().interrupt();
                            return;
                        }
                    }

                    if (current <= 10) {
                        System.out.println("Even: " + current);
                        current++;
                    }
                    lock.notifyAll();
                }
            }
        }
    }

    static class OddRunnable implements Runnable {
        @Override
        public void run() {
            synchronized (lock) {
                while (current <= 10) {
                    while (current % 2 == 0) {
                        try {
                            lock.wait();
                        } catch (InterruptedException e) {
                            Thread.currentThread().interrupt();
                            return;
                        }
                    }

                    if (current <= 10) {
                        System.out.println("Odd: " + current);
                        current++;
                    }
                    lock.notifyAll();
                }
            }
        }
    }

    public static void main(String[] args) {
        Thread evenThread = new Thread(new EvenRunnable());
        Thread oddThread = new Thread(new OddRunnable());

        evenThread.start();
        oddThread.start();
    }
}       
