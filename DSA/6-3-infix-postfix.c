#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// Define a stack structure for operators
struct Stack {
    char items[MAX_STACK_SIZE];
    int top;
};

// Initialize an empty stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Check the top element of the stack
char peek(struct Stack* stack) {
    return stack->items[stack->top];
}

// Push an element onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++(stack->top)] = item;
}

// Pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

// Check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Check the precedence of an operator
int precedence(char ch) {
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    return 0;
}

// Convert infix expression to postfix notation
void infixToPostfix(char* infix) {
    struct Stack operatorStack;
    initialize(&operatorStack);

    int infixLen = strlen(infix);
    char postfix[infixLen];
    int postfixIndex = 0;

    for (int i = 0; i < infixLen; i++) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            postfix[postfixIndex++] = ch;
        } else if (isOperator(ch)) {
            while (!isEmpty(&operatorStack) &&
                   precedence(peek(&operatorStack)) >= precedence(ch)) {
                postfix[postfixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, ch);
        } else if (ch == '(') {
            push(&operatorStack, ch);
        } else if (ch == ')') {
            while (!isEmpty(&operatorStack) && peek(&operatorStack) != '(') {
                postfix[postfixIndex++] = pop(&operatorStack);
            }
            if (!isEmpty(&operatorStack) && peek(&operatorStack) == '(') {
                pop(&operatorStack); // Pop the opening parenthesis
            }
        }
    }

    while (!isEmpty(&operatorStack)) {
        postfix[postfixIndex++] = pop(&operatorStack);
    }

    postfix[postfixIndex] = '\0';
    printf("Postfix notation: %s\n", postfix);
}

int main() {
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}

