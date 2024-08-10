//2.4
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

// Function to find the height of a binary tree
int height(struct Node* root) {
    if (root == NULL)
        return -1; // Height of an empty tree is -1

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Height of the tree is the maximum height of left and right subtrees plus 1
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Find the height of the binary tree
    int treeHeight = height(root);

    printf("Height of the binary tree: %d\n", treeHeight);

    return 0;
}
