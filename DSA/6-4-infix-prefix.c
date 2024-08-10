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

// Convert infix expression to prefix notation
void infixToPrefix(char* infix) {
    struct Stack operatorStack;
    initialize(&operatorStack);

    int infixLen = strlen(infix);
    char prefix[infixLen];
    int prefixIndex = 0;

    for (int i = infixLen - 1; i >= 0; i--) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            prefix[prefixIndex++] = ch;
        } else if (isOperator(ch)) {
            while (!isEmpty(&operatorStack) &&
                   precedence(peek(&operatorStack)) > precedence(ch)) {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, ch);
        } else if (ch == ')') {
            push(&operatorStack, ch);
        } else if (ch == '(') {
            while (!isEmpty(&operatorStack) && peek(&operatorStack) != ')') {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            if (!isEmpty(&operatorStack) && peek(&operatorStack) == ')') {
                pop(&operatorStack); // Pop the closing parenthesis
            }
        }
    }

    while (!isEmpty(&operatorStack)) {
        prefix[prefixIndex++] = pop(&operatorStack);
    }

    prefix[prefixIndex] = '\0';

    // Reverse the prefix expression to obtain the correct order
    int start = 0;
    int end = prefixIndex - 1;
    while (start < end) {
        char temp = prefix[start];
        prefix[start] = prefix[end];
        prefix[end] = temp;
        start++;
        end--;
    }

    printf("Prefix notation: %s\n", prefix);
}

int main() {
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix);
    return 0;
}

