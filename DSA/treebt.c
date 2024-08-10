#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Define a structure for a queue node
struct QueueNode {
    struct Node* data;
    struct QueueNode* next;
};

// Define a structure for a queue
struct Queue {
    struct QueueNode *front, *rear;
};

// Function to create a new binary tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new queue node
struct QueueNode* createQueueNode(struct Node* data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmptyQueue(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue a node into the queue
void enqueue(struct Queue* queue, struct Node* data) {
    struct QueueNode* newNode = createQueueNode(data);
    if (isEmptyQueue(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue a node from the queue
struct Node* dequeue(struct Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    struct QueueNode* temp = queue->front;
    struct Node* data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to insert a node into the binary tree
void insertNode(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
    } else {
        struct Queue* queue = createQueue();
        enqueue(queue, *root);
        while (!isEmptyQueue(queue)) {
            struct Node* temp = dequeue(queue);
            if (temp->left == NULL) {
                temp->left = newNode;
                break;
            } else {
                enqueue(queue, temp->left);
            }
            if (temp->right == NULL) {
                temp->right = newNode;
                break;
            } else {
                enqueue(queue, temp->right);
            }
        }
    }
}

// Function to display the binary tree level-wise
void displayTreeLevelWise(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue* queue = createQueue();
    enqueue(queue, root);

    while (!isEmptyQueue(queue)) {
        int levelNodes = queue->rear - queue->front + 1;

        for (int i = 0; i < levelNodes; i++) {
            struct Node* temp = dequeue(queue);
            printf("%d ", temp->data);

            if (temp->left != NULL)
                enqueue(queue, temp->left);
            if (temp->right != NULL)
                enqueue(queue, temp->right);
        }

        printf("\n");
    }
}

int main() {
    struct Node* root = NULL;

    // Insert nodes into the binary tree
    insertNode(&root, 1);
    insertNode(&root, 2);
    insertNode(&root, 3);
    insertNode(&root, 4);
    insertNode(&root, 5);
    insertNode(&root, 6);

    // Display the binary tree level-wise
    printf("Binary Tree Level-wise:\n");
    displayTreeLevelWise(root);

    return 0;
}

