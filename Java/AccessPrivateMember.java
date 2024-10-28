// Superclass
class Superclass {
    // Private member
    private String privateMessage = "Hello from the Superclass!";

    // Public method to access the private member
    public String getPrivateMessage() {
        return privateMessage;
    }
}

// Subclass
class Subclass extends Superclass {
    // Method to display the private message from the superclass
    public void displayMessage() {
        // Accessing the private member through the public method of the superclass
        String message = getPrivateMessage();
        System.out.println("Accessing private member in Subclass: " + message);
    }
}

// Main class
public class AccessPrivateMember {
    public static void main(String[] args) {
        Subclass obj = new Subclass(); // Creating an instance of Subclass
        obj.displayMessage(); // Calling the method to display the private message
    }
}
