#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Include ctype.h for isalnum

#define MAX_SIZE 100

// Stack implementation
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char c) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = c;
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0'; // Empty stack marker
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack stack;
    initialize(&stack);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.data[stack.top] == '(') {
                pop(&stack);
            }
        } else {
            while (!isEmpty(&stack) && precedence(token) <= precedence(stack.data[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
