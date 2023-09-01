class Stack {
    constructor() {
        this.stack = [];
        this.top = -1;
    }

    push(value) {
        this.stack[++this.top] = value;
        console.log(`Pushed ${value} onto the stack`);
    }

    pop() {
        if (this.top < 0) {
            console.log("Stack Underflow");
            return -1;
        }
        const value = this.stack[this.top--];
        console.log(`Popped ${value} from the stack`);
        return value;
    }

    peek() {
        if (this.top < 0) {
            console.log("Stack is empty");
            return -1;
        }
        return this.stack[this.top];
    }

    isEmpty() {
        return this.top === -1;
    }

    printStack() {
        if (this.isEmpty()) {
            console.log("Stack is empty");
            return;
        }
        console.log("Elements in the stack:");
        for (let i = this.top; i >= 0; i--) {
            console.log(this.stack[i]);
        }
    }
}

const stack = new Stack();
let choice, value;

const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

function menu() {
    console.log("Stack Menu:");
    console.log("1. Push");
    console.log("2. Pop");
    console.log("3. Peek");
    console.log("4. Check if stack is empty");
    console.log("5. Print stack");
    console.log("6. Exit");
    readline.question("Enter your choice: ", option => {
        choice = parseInt(option);
        switch (choice) {
            case 1:
                readline.question("Enter value to push: ", val => {
                    value = parseInt(val);
                    stack.push(value);
                    menu();
                });
                break;
            case 2:
                stack.pop();
                menu();
                break;
            case 3:
                console.log(`Top element: ${stack.peek()}`);
                menu();
                break;
            case 4:
                console.log(`Is stack empty? ${stack.isEmpty() ? "Yes" : "No"}`);
                menu();
                break;
            case 5:
                stack.printStack();
                menu();
                break;
            case 6:
                console.log("Exiting...");
                readline.close();
                break;
            default:
                console.log("Invalid choice");
                menu();
        }
    });
}

menu();
