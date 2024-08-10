#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d.\n", element);
        return;
    }
    stack->data[++stack->top] = element;
    printf("%d pushed into the stack.\n", element);
}

void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    printf("%d popped from the stack.\n", stack->data[stack->top]);
    stack->top--;
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Nothing to peek.\n");
        return -1; // Return a sentinel value to indicate an error
    }
    return stack->data[stack->top];
}

void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Nothing to display.\n");
        return;
    }
    printf("Stack elements from top to bottom: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    int choice, element;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&stack, element);
                break;
            case 2:
                pop(&stack);
                break;
            case 3: {
                int topElement = peek(&stack);
                if (topElement != -1) {
                    printf("Top element: %d\n", topElement);
                }
                break;
            }
            case 4:
                display(&stack);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

