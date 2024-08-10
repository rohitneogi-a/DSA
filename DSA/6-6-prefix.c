#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void push(int item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePrefix(char prefix[]) {
    int length = strlen(prefix);
    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            int operand1 = pop();
            int operand2 = pop();
            switch (prefix[i]) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
            }
        } else if (prefix[i] >= '0' && prefix[i] <= '9') {
            push(prefix[i] - '0');
        }
    }
    return pop();
}

int main() {
    char prefix[MAX_SIZE];
    printf("Enter a prefix expression: ");
    fgets(prefix, sizeof(prefix), stdin);
    int result = evaluatePrefix(prefix);
    printf("Result: %d\n", result);
    return 0;
}

