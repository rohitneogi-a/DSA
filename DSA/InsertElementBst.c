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

    struct Node* current = root;
    struct Node* parent = NULL;

    while (1) {
        parent = current;
        if (value < current->data) {
            current = current->left;
            if (current == NULL) {
                parent->left = createNode(value);
                break;
            }
        } else {
            current = current->right;
            if (current == NULL) {
                parent->right = createNode(value);
                break;
            }
        }
    }

    return root;
}

// Function to display the binary search tree in inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = NULL;

    // Insert elements into the binary search tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Display the original binary search tree
    printf("Original Binary Search Tree (Inorder traversal): ");
    inorderTraversal(root);
    printf("\n");

    // Insert a specific element into the binary search tree
    int elementToInsert = 55;
    root = insert(root, elementToInsert);

    // Display the modified binary search tree
    printf("Modified Binary Search Tree (Inorder traversal): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
