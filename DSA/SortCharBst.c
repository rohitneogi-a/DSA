#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a binary search tree node
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char value) {
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

// Function to insert a character into the binary search tree
struct Node* insert(struct Node* root, char value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to perform inorder traversal of the binary search tree
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

int main() {
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);

    struct Node* root = NULL;

    // Insert characters of the name into the binary search tree
    for (int i = 0; i < strlen(name); i++) {
        root = insert(root, name[i]);
    }

    // Display the sorted sequence of characters
    printf("Sorted sequence of characters: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
