//2.10
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
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

// Function to count the number of siblings of a given node in a binary tree
int countSiblings(struct Node* root, int target) {
    if (root == NULL)
        return 0;
    if ((root->left != NULL && root->left->data == target) || (root->right != NULL && root->right->data == target))
        return 1;
    return countSiblings(root->left, target) + countSiblings(root->right, target);
}

int main() {
    // Constructing the binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int targetNode = 4; // Example: Find the number of siblings of node with data 4

    // Count the number of siblings of the given node
    int siblingCount = countSiblings(root, targetNode);

    printf("Number of siblings of node %d: %d\n", targetNode, siblingCount);

    return 0;
}
