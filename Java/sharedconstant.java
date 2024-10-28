// Interface with shared constants
interface Constants {
    // Shared constants
    int MAX_USERS = 100;
    String APP_NAME = "MyApplication";
}

// Class implementing the interface
class User {
    String username;

    User(String username) {
        this.username = username;
    }

    void displayInfo() {
        System.out.println("Username: " + username);
        System.out.println("Application Name: " + Constants.APP_NAME);
        System.out.println("Max Users Allowed: " + Constants.MAX_USERS);
    }
}

// Main class to demonstrate the usage of shared constants
public class sharedconstant {
    public static void main(String[] args) {
        // Creating user instances
        User user1 = new User("Alice");
        User user2 = new User("Bob");

        // Displaying user information
        user1.displayInfo();
        System.out.println(); // Print a new line for better output separation
        user2.displayInfo();
    }
}
