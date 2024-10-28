
// File: ClassA.java 
package pack1;

public class ClassA {
    // Public variable: Accessible from any class in any package 
    public int publicVar = 1;

    // Private variable: Accessible only within this class 
    private int privateVar = 2;

    // Protected variable: Accessible in the same package and by subclasses 
    protected int protectedVar = 3;

    // Default variable: Accessible only within the same package 
    int defaultVar = 4;

    // Method to display all variables 
    public void display() {
        System.out.println("Public Variable = " + publicVar);
        System.out.println("Private Variable = " + privateVar);
        System.out.println("Protected Variable = " + protectedVar);
        System.out.println("Default Variable = " + defaultVar);
    }
}