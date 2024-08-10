//2.2
#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure for a queue node
struct QueueNode {
    struct Node* data;
    struct QueueNode* next;
};

// Function to create a new tree node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to enqueue a node in the queue
void enqueue(struct QueueNode** front, struct QueueNode** rear, struct Node* value) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }

    (*rear)->next = newNode;
    *rear = newNode;
}

// Function to dequeue a node from the queue
struct Node* dequeue(struct QueueNode** front, struct QueueNode** rear) {
    if (*front == NULL)
        return NULL;

    struct Node* temp = (*front)->data;
    struct QueueNode* tempNode = *front;

    *front = (*front)->next;

    if (*front == NULL)
        *rear = NULL;

    free(tempNode);
    return temp;
}

// Function to insert a node into the binary tree
void insertNode(struct Node** root, int value) {
    struct Node* newNode = createNode(value);

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct QueueNode* front = NULL;
    struct QueueNode* rear = NULL;
    enqueue(&front, &rear, *root);

    while (1) {
        struct Node* temp = dequeue(&front, &rear);

        if (temp->left == NULL) {
            temp->left = newNode;
            break;
        } else {
            enqueue(&front, &rear, temp->left);
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            break;
        } else {
            enqueue(&front, &rear, temp->right);
        }
    }
}

// Function to display the binary tree level-wise
void displayLevelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct QueueNode* front = NULL;
    struct QueueNode* rear = NULL;

    enqueue(&front, &rear, root);

    while (front != NULL) {
        struct Node* temp = dequeue(&front, &rear);

        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(&front, &rear, temp->left);

        if (temp->right != NULL)
            enqueue(&front, &rear, temp->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;

    // Inserting nodes into the binary tree
    insertNode(&root, 1);
    insertNode(&root, 2);
    insertNode(&root, 3);
    insertNode(&root, 4);
    insertNode(&root, 5);

    // Displaying the binary tree level-wise
    printf("Level Order Traversal: ");
    displayLevelOrder(root);

    return 0;
}