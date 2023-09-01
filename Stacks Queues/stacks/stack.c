#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = value;
    printf("Pushed %d onto the stack\n", value);
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    int value = stack[top--];
    printf("Popped %d from the stack\n", value);
    return value;
}

int peek() {
    if (top < 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

void printStack() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Elements in the stack:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, value, limit;

    printf("Enter the maximum number of elements for the stack: ");
    scanf("%d", &limit);
    
    do {
        printf("Stack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if stack is empty\n");
        printf("5. Print stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Stack is full\n");
                    break;
                }
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Top element: %d\n", peek());
                break;
            case 4:
                printf("Is stack empty? %s\n", isEmpty() ? "Yes" : "No");
                break;
            case 5:
                printStack();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
