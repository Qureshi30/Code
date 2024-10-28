import java.io.*;
import java.util.Scanner;

public class writefile {
    public static void main(String[] args) {
        // Creating a new File
        File newfile = new File("new.txt");

        try {
            // Create a new file if it doesn't exist
            if (newfile.createNewFile()) {
                System.out.println("File Successfully Created");
            } else {
                System.out.println("File already exists.");
            }
        } catch (IOException e) {
            System.out.println("Unable to create new file");
            e.printStackTrace();
        }

        // Writing to the file using FileWriter
        try (FileWriter writeinit = new FileWriter("new.txt")) {
            // Writing content to the file
            writeinit.write("Here is the program to write in the file using FileWriter");
            System.out.println("Successfully wrote to the file.");
        } catch (IOException e) {
            System.out.println("Unable to write to the new file");
            e.printStackTrace();
        }

        // Reading from the file using Scanner
        File filereader = new File("new.txt");

        try (Scanner sc = new Scanner(filereader)) {
            // Reading content from the file
            while (sc.hasNextLine()) {
                String line = sc.nextLine();
                System.out.println(line);
            }
            System.out.println("File Successfully Read");
        } catch (FileNotFoundException e) {
            System.out.println("Unable to open the file");
            e.printStackTrace();
        }
    }
}
