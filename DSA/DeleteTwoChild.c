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

// Function to find the minimum value node in a binary search tree
struct BSTNode* minValueNode(struct BSTNode* node) {
    struct BSTNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node with two children from the binary search tree
struct BSTNode* deleteNode(struct BSTNode* root, int key) {
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key, then it lies in the left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    // If the key to be deleted is greater than the root's key, then it lies in the right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    // If the key to be deleted is the same as the root's key, then this is the node to be deleted
    else {
        // Node with only one child or no child
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
        struct BSTNode* temp = minValueNode(root->right);

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

    // Delete a node with two children (e.g., 50)
    int keyToDelete = 50;
    root = deleteNode(root, keyToDelete);

    printf("Binary Search Tree after deletion of node %d: ", keyToDelete);
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
