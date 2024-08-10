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

// Function to insert an integer into the binary search tree
struct Node* insert(struct Node* root, int value) {
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
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to free the memory allocated for the binary search tree
void freeTree(struct Node* root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Input integers
    int nums[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Create a binary search tree and insert the integers
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, nums[i]);
    }

    // Display the sorted sequence of integers
    printf("Sorted sequence of integers: ");
    inorderTraversal(root);
    printf("\n");

    // Free the memory allocated for the binary search tree
    freeTree(root);

    return 0;
}
