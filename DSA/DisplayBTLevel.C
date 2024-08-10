//2.1
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
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

// Function to insert a node into the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

// Function to display the binary tree level-wise
void displayLevelOrder(struct Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        displayLevelOrder(root->left, level - 1);
        displayLevelOrder(root->right, level - 1);
    }
}

// Function to get the height of the binary tree
int getHeight(struct Node* root) {
    if (root == NULL)
        return 0;
    else {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}

// Function to display the binary tree level-wise
void displayTreeLevelWise(struct Node* root) {
    int height = getHeight(root);
    for (int i = 1; i <= height; i++) {
        printf("Level %d: ", i);
        displayLevelOrder(root, i);
        printf("\n");
    }
}

int main() {
    struct Node* root = NULL;

    // Insert nodes into the binary tree
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Display the binary tree level-wise
    printf("Binary Tree Level-wise:\n");
    displayTreeLevelWise(root);

    return 0;
}
