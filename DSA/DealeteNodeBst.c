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

// Function to perform in-order traversal of the binary search tree
void inOrderTraversal(struct BSTNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to delete a node with no child from the binary search tree
struct BSTNode* deleteNode(struct BSTNode* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with no child or one child
        if (root->left == NULL) {
            struct BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct BSTNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct BSTNode* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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

    printf("Binary Search Tree before deletion: ");
    inOrderTraversal(root);
    printf("\n");

    // Delete a node with no child (e.g., 20)
    int keyToDelete = 20;
    root = deleteNode(root, keyToDelete);

    printf("Binary Search Tree after deletion of node %d: ", keyToDelete);
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
