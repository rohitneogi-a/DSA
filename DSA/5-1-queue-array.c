#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to initialize an empty queue
void initializeQueue(int *queue, int *front, int *rear) {
    *front = -1;
    *rear = -1;
}

// Function to check if the queue is empty
int isEmpty(int front, int rear) {
    return (front == -1 && rear == -1);
}

// Function to check if the queue is full
int isFull(int rear) {
    return (rear == MAX_SIZE - 1);
}

// Function to add an element to the rear of the queue (enqueue operation)
// Function to add an element to the rear of the queue (enqueue operation)
// Function to add an element to the rear of the queue (enqueue operation)
void enqueue(int *queue, int *front, int *rear, int element) {
    if (isFull(*rear)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(*front, *rear)) {
        *rear = 0;
        *front = 0; // Initialize front when the queue is empty
        queue[*rear] = element;
    } else {
        (*rear)++;
        queue[*rear] = element;
    }

    printf("%d enqueued to the queue.\n", element);
}


// Function to remove an element from the front of the queue (dequeue operation)
void dequeue(int *queue, int *front, int *rear) {
    if (isEmpty(*front, *rear)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    int removedElement = queue[*front];
    if (*front == *rear) {
        // If there was only one element in the queue
        initializeQueue(queue, front, rear);
    } else {
        (*front)++;
    }

    printf("%d dequeued from the queue.\n", removedElement);
}

// Function to return the value of the FRONT element (peek operation)
int peek(int *queue, int front, int rear) {
    if (isEmpty(front, rear)) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1; // Return a sentinel value to indicate an error
    }

    return queue[front];
}

// Function to display the elements of the queue
void display(int *queue, int front, int rear) {
    if (isEmpty(front, rear)) {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int queue[MAX_SIZE];
    int front, rear;
    initializeQueue(queue, &front, &rear);

    int choice, element;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(queue, &front, &rear, element);
;
                break;
            case 2:
                dequeue(queue, &front, &rear);
                break;
            case 3:
                element = peek(queue, front, rear);
                if (element != -1) {
                    printf("Front element: %d\n", element);
                }
                break;
            case 4:
                display(queue, front, rear);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

