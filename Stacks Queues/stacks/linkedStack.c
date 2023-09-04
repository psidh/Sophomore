#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

int isEmpty() {
    return top == NULL;
}

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // if (newNode == NULL) {
    //     printf("Memory allocation failed\n");
    //     return;
    // }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto the stack\n", value);
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    printf("Popped %d from the stack\n", value);
    return value;
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void printStack() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Elements in the stack:\n");
    struct Node* current = top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main() {
    
    push(24);
    push(23);
    push(22);
    printStack();
    pop();
    pop();
    printStack(); 
    peek();
    printStack();
    isEmpty();
    return 0;
}
