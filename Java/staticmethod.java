public class staticmethod {
    static int a = 8;
    static int b;
    // Instance method
    void meth(int x) {
        System.out.println("x = " + x);
        System.out.println("a = " + a);
        System.out.println("b = " + b);
    }
    // Static block
    static {
        System.out.println("Static Block Initialization");
        b = a + 7;
    }
    public static void main(String[] args) {
// Create an instance to call the non-static method
        staticmethod obj = new staticmethod();
        obj.meth(24);
    }
}