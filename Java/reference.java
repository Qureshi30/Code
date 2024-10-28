public class reference {
    public static void passByValue(int x) {
        x = 50;
        System.out.println("Inside passByValue method, x = " + x);
    }
    public static void passByReference(NumberWrapper obj) {
        obj.value = 50;
        System.out.println("Inside passByReference method, obj.value = " +
                obj.value);
    }

    public static void main(String[] args) {
        int num = 10;
        System.out.println("Before passByValue method, num = " + num);
        passByValue(num);
        System.out.println("After passByValue method, num = " + num);

        NumberWrapper wrapper = new NumberWrapper(10);
        System.out.println("Before passByReference method, wrapper.value = " +
                wrapper.value);
        passByReference(wrapper);
        System.out.println("After passByReference method, wrapper.value = " +
                wrapper.value);
    }
}

class NumberWrapper {
    int value;
    NumberWrapper(int value) {
        this.value = value;
    }
}