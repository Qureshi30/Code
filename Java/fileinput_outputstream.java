import java.io.*;

public class fileinput_outputstream {
    public static void main(String[] args) {
        // Data to be written to the file
        byte[] b1 = {'A', 'B', 'C', 'D', 'E', 'F'};

        // Writing data to the file using FileOutputStream
        try (FileOutputStream fos = new FileOutputStream("new.txt")) {
            fos.write(b1);
            System.out.println("File written successfully.");
        } catch (IOException e) {
            System.out.println("An error occurred while writing to the file.");
            e.printStackTrace();
        }

        // Reading data from the file using FileInputStream
        try (FileInputStream fis = new FileInputStream("new.txt")) {
            int b;
            System.out.println("Reading from file:");
            while ((b = fis.read()) != -1) {
                System.out.print((char) b);  // Casting byte to char to print as characters
            }
            System.out.println(); // New line after reading
        } catch (IOException e) {
            System.out.println("An error occurred while reading from the file.");
            e.printStackTrace();
        }
    }
}
