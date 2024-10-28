// Superclass
class Parent {
    String name = "Parent";

    // Constructor of the superclass
    Parent() {
        System.out.println("Parent constructor called");
    }

    void display() {
        System.out.println("Name from Parent: " + name);
    }
}

// Subclass
class Child extends Parent {
    String name = "Child"; // Shadowing the parent's field

    // Constructor of the subclass
    Child() {
        super(); // Calling the superclass constructor
        System.out.println("Child constructor called");
    }

    void display() {
        super.display(); // Calling the superclass method
        System.out.println("Name from Child: " + name);
    }
}

// Main class
public class superkeyword {
    public static void main(String[] args) {
        Child child = new Child(); // Creating an instance of Child
        child.display(); // Calling the display method
    }
}
