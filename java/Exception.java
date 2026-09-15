public class Exception {
    
    void myException() throws ArithmeticException {
        int a = 30, b = 0;
        int c = a / b; // This will throw ArithmeticException
        System.out.println("Result: " + c);
    }
    void myException1(){
        throw new ArithmeticException("Division by zero is not allowed."); // This will throw ArithmeticException
    }
    public static void main(String[] args) {
        try {
            int a = 30, b = 0;
            int c = a / b; // This will throw ArithmeticException
            System.out.println("Result: " + c);
        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero is not allowed.");
        } finally {
            System.out.println("Execution completed.");
        }
        Exception obj = new Exception();
        try {
            obj.myException();
        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero is not allowed.");
        } finally {
            System.out.println("Execution completed.");
        }
    }
}
