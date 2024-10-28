// For even numbers
class EvenThread extends Thread {
    private int max;

    EvenThread(int max) {
        this.max = max;
    }

    public void run() {
        for (int i = 2; i <= max; i += 2) {
            System.out.println("Even: " + i);
            try {
                Thread.sleep(500); // Pausing the thread for 500ms
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

// For odd numbers
class OddThread extends Thread {
    private int max;

    OddThread(int max) {
        this.max = max;
    }

    public void run() {
        for (int i = 1; i <= max; i += 2) {
            System.out.println("Odd: " + i);
            try {
                Thread.sleep(500); // Pausing the thread for 500ms
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class evenoddmultithreading {
    public static void main(String[] args) {
        // Create and start threads
        EvenThread evenThread = new EvenThread(10);  // Print even numbers up to 10
        OddThread oddThread = new OddThread(10);    // Print odd numbers up to 10

        evenThread.start();  // Start the even thread
        oddThread.start();   // Start the odd thread
    }
}
