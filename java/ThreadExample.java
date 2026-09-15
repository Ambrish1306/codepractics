class MyThread implements Runnable {
    @Override
    public void run() {
        System.out.println("Thread is running via Runnable!");
    }
}
class MyThread1 extends Thread {
    @Override
    public void run() {
        System.out.println("Thread is running via class inheritance!");
    }
}
public class ThreadExample {
    public static void main(String[] args) {
        MyThread task = new MyThread();  // Create an instance of the Runnable task
        Thread thread = new Thread(task); // Pass the task to the Thread constructor
        thread.start();                   // Start the thread (allocates new stack)
        /********2nd method**************/
        MyThread1 thread2 = new MyThread1();
        thread2.start(); // Always call start(), never call run() directly!
    }
}