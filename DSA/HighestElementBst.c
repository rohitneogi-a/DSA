#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary search tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to count the number of nodes present in the BST
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to find the highest element present in the BST
int findHighestElement(struct Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int main() {
    // Create a binary search tree
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Count the number of nodes in the BST
    int nodeCount = countNodes(root);
    printf("Number of nodes in the BST: %d\n", nodeCount);

    // Find and display the highest element in the BST
    int highestElement = findHighestElement(root);
    printf("Highest element in the BST: %d\n", highestElement);

    return 0;
}
