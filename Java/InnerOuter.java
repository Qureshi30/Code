class Outer {
    int x = 100; // Outer class variable

    void test() {
        Inner obj = new Inner();
        obj.test();
        System.out.println("This is from outer class and x here is " + x);
    }

    class Inner {
        int x = 10;

        void test() {
            System.out.println("This is from inner class and x here is " + x);
        }
    }
}

public class InnerOuter {
    public static void main(String[] args) {
        Outer obj2 = new Outer();
        obj2.test();

    }
}
