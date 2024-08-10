//2.9
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Define a structure for a binary tree node
struct Node {
    int data;
    int leftChildIndex;
    int rightChildIndex;
};

// Function to create a new binary tree node
struct Node* createNode(int data, int leftChildIndex, int rightChildIndex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->leftChildIndex = leftChildIndex;
    newNode->rightChildIndex = rightChildIndex;
    return newNode;
}

// Function to count the number of nodes in a binary tree
int countNodes(struct Node* tree[], int rootIndex) {
    if (rootIndex == -1 || tree[rootIndex] == NULL)
        return 0;
    if (tree[rootIndex]->leftChildIndex == -1 && tree[rootIndex]->rightChildIndex == -1)
        return 1;
    int leftCount = countNodes(tree, tree[rootIndex]->leftChildIndex);
    int rightCount = countNodes(tree, tree[rootIndex]->rightChildIndex);
    return 1 + leftCount + rightCount;
}


int main() {
    // Constructing the binary tree using array representation
    struct Node* tree[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++)
        tree[i] = NULL;

    tree[0] = createNode(1, 1, 2);
    tree[1] = createNode(2, 3, 4);
    tree[2] = createNode(3, 5, 6);
    tree[3] = createNode(4, -1, -1);
    tree[4] = createNode(5, -1, -1);
    tree[5] = createNode(6, -1, -1);

    // Count the number of nodes
    int nodeCount = countNodes(tree, 0);

    printf("Number of nodes: %d\n", nodeCount);

    return 0;
}
