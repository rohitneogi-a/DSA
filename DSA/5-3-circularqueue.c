#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Function to calculate the next index in a circular manner
int nextIndex(int index) {
    return (index + 1) % MAX_SIZE;
}

// Structure for the circular queue
struct CircularQueue {
    int data[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize an empty circular queue
void initializeCircularQueue(struct CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1);
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* queue) {
    return (nextIndex(queue->rear) == queue->front);
}

// Function to insert an element into the circular queue
void insert(struct CircularQueue* queue, int element) {
    if (isFull(queue)) {
        printf("Circular Queue is full. Cannot insert.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = nextIndex(queue->rear);
    }

    queue->data[queue->rear] = element;
    printf("%d inserted into the circular queue.\n", element);
}

// Function to delete an element from the circular queue
void delete(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue is empty. Cannot delete.\n");
        return;
    }

    int deletedElement = queue->data[queue->front];

    if (queue->front == queue->rear) {
        initializeCircularQueue(queue);
    } else {
        queue->front = nextIndex(queue->front);
    }

    printf("%d deleted from the circular queue.\n", deletedElement);
}

// Function to return the value of the FRONT element (peek operation)
int peek(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue is empty. Nothing to peek.\n");
        return -1; // Return a sentinel value to indicate an error
    }

    return queue->data[queue->front];
}

// Function to display the elements of the circular queue
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue is empty. Nothing to display.\n");
        return;
    }

    int current = queue->front;

    printf("Circular Queue elements: ");
    while (current != queue->rear) {
        printf("%d ", queue->data[current]);
        current = nextIndex(current);
    }
    printf("%d\n", queue->data[current]);
}

int main() {
    struct CircularQueue queue;
    initializeCircularQueue(&queue);

    int choice, element;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insert(&queue, element);
                break;
            case 2:
                delete(&queue);
                break;
            case 3:
                element = peek(&queue);
                if (element != -1) {
                    printf("Front element: %d\n", element);
                }
                break;
            case 4:
                display(&queue);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

