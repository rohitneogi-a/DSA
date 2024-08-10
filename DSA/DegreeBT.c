//2.5
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

// Function to find the degree of a given node in a binary tree
int degree(struct Node* root, int target) {
    if (root == NULL)
        return 0; // Node not found, so degree is 0

    // If the current node contains the target data
    if (root->data == target) {
        int deg = 0;
        if (root->left != NULL)
            deg++;
        if (root->right != NULL)
            deg++;
        return deg;
    }

    // Recursively search in left and right subtrees
    int leftDeg = degree(root->left, target);
    if (leftDeg != 0)
        return leftDeg;

    int rightDeg = degree(root->right, target);
    return rightDeg;
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

    int targetNode = 3; // Example: Find the degree of node with data 3

    // Find the degree of the given node
    int nodeDegree = degree(root, targetNode);

    printf("Degree of node %d: %d\n", targetNode, nodeDegree);

    return 0;
}
