#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary search tree node
struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

// Function to create a new node for a binary search tree
struct BSTNode* createBSTNode(int value) {
    struct BSTNode* newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
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
struct BSTNode* insertBSTNode(struct BSTNode* root, int value) {
    if (root == NULL)
        return createBSTNode(value);

    if (value < root->data)
        root->left = insertBSTNode(root->left, value);
    else if (value > root->data)
        root->right = insertBSTNode(root->right, value);

    return root;
}

// Function to search for a value in a binary search tree recursively
struct BSTNode* searchBST(struct BSTNode* root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return searchBST(root->left, value);
    else
        return searchBST(root->right, value);
}

// Function to print the elements of the binary search tree in order
void inOrderTraversal(struct BSTNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct BSTNode* root = NULL;
    
    // Insert elements into the binary search tree
    root = insertBSTNode(root, 50);
    root = insertBSTNode(root, 30);
    root = insertBSTNode(root, 70);
    root = insertBSTNode(root, 20);
    root = insertBSTNode(root, 40);
    root = insertBSTNode(root, 60);
    root = insertBSTNode(root, 80);

    // Search for elements in the binary search tree
    int searchValue = 30;
    struct BSTNode* resultNode = searchBST(root, searchValue);
    if (resultNode != NULL)
        printf("Element %d found in the binary search tree.\n", searchValue);
    else
        printf("Element %d not found in the binary search tree.\n", searchValue);

    // Print the elements of the binary search tree in order
    printf("Elements of the binary search tree in order: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
