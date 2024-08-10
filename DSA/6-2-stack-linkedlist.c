#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the stack
struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

// Function to initialize an empty stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed into the stack.\n", element);
}

// Function to pop an element from the stack
void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    struct Node* poppedNode = stack->top;
    stack->top = poppedNode->next;
    printf("%d popped from the stack.\n", poppedNode->data);
    free(poppedNode);
}

// Function to return the value of the topmost element (peek operation)
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Nothing to peek.\n");
        return -1; // Return a sentinel value to indicate an error
    }
    return stack->top->data;
}

// Function to display the elements of the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Nothing to display.\n");
        return;
    }
    printf("Stack elements from top to bottom: ");
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
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

