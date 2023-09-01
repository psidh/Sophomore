import java.util.Scanner;

public class StackMenu {
    private int[] stack;
    private int top;

    public StackMenu(int maxSize) {
        stack = new int[maxSize];
        top = -1;
    }

    public void push(int value) {
        if (top >= stack.length - 1) {
            System.out.println("Stack Overflow");
            return;
        }
        stack[++top] = value;
        System.out.println("Pushed " + value + " onto the stack");
    }

    public int pop() {
        if (top < 0) {
            System.out.println("Stack Underflow");
            return -1;
        }
        int value = stack[top--];
        System.out.println("Popped " + value + " from the stack");
        return value;
    }

    public int peek() {
        if (top < 0) {
            System.out.println("Stack is empty");
            return -1;
        }
        return stack[top];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public void printStack() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return;
        }
        System.out.println("Elements in the stack:");
        for (int i = top; i >= 0; i--) {
            System.out.println(stack[i]);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the maximum number of elements for the stack: ");
        int limit = scanner.nextInt();
        StackMenu stack = new StackMenu(limit);
        int choice, value;

        do {
            System.out.println("Stack Menu:");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Peek");
            System.out.println("4. Check if stack is empty");
            System.out.println("5. Print stack");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    if (stack.isFull()) {
                        System.out.println("Stack is full");
                        break;
                    }
                    System.out.print("Enter value to push: ");
                    value = scanner.nextInt();
                    stack.push(value);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    System.out.println("Top element: " + stack.peek());
                    break;
                case 4:
                    System.out.println("Is stack empty? " + (stack.isEmpty() ? "Yes" : "No"));
                    break;
                case 5:
                    stack.printStack();
                    break;
                case 6:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        } while (choice != 6);
    }
}
