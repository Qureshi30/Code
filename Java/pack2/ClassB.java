// File: ClassB.java 
package pack2;

// Importing ClassA from pack1 
import pack1.ClassA;

class SubClass extends ClassA {
    // In the subclass, we can access public and protected variables from ClassA 
    void show() {
        System.out.println("Accessing public variable from SubClass = " + publicVar);
        System.out.println("Accessing protected variable from SubClass = " +
                protectedVar);
    }
}
public class ClassB {
    public static void main(String[] args) {
// Creating an object of ClassA in a different package 
        ClassA obj = new ClassA();
        obj.display();  // Accessing all variables inside ClassA from the same package
// Creating an object of SubClass (extends ClassA) 
        SubClass sub = new SubClass();
        sub.show();  // Accessing public and protected variables from SubClass
    }
} 