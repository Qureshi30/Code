class A {
    void callme() {
        System.out.println("Method A got a call");
    }
}

class B extends A {
    void callme() {
        System.out.println("Method B got a call");
    }
}

class C extends A {
    void callme() {
        System.out.println("Method C got a call");
    }
}
public class dynamicmethoddispatch {
    public static void main(String[] args) {
        A a = new A();
        B b = new B();
        C c = new C();

        A r;

        r = a;
        r.callme();
        r = b;
        r.callme();
        r = c;
        r.callme();
    }
}
