#include <iostream>
using namespace std;

class Stack {
private:
    int* stack;
    int top;
    int maxSize;

public:
    Stack(int size) {
        stack = new int[size];
        top = -1;
        maxSize = size;
    }

    ~Stack() {
        delete[] stack;
    }

    void push(int value) {
        if (top >= maxSize - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        stack[++top] = value;
        cout << "Pushed " << value << " onto the stack" << endl;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int value = stack[top--];
        cout << "Popped " << value << " from the stack" << endl;
        return value;
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stack[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == maxSize - 1;
    }

    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Elements in the stack:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
};

int main() {
    int limit, choice, value;
    cout << "Enter the maximum number of elements for the stack: ";
    cin >> limit;

    Stack stack(limit);

    do {
        cout << "Stack Menu:" <<
