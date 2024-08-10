#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure for a binary tree node
struct BTNode {
    int data;
    struct BTNode* left;
    struct BTNode* right;
};

// Define a structure for a binary search tree node
struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

// Function to create a new node for a binary tree
struct BTNode* createBTNode(int value) {
    struct BTNode* newNode = (struct BTNode*)malloc(sizeof(struct BTNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

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

// Function to insert a value into the binary tree
struct BTNode* insertBTNode(struct BTNode* root, int value) {
    if (root == NULL)
        return createBTNode(value);

    if (value < root->data)
        root->left = insertBTNode(root->left, value);
    else if (value > root->data)
        root->right = insertBTNode(root->right, value);

    return root;
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

// Function to search for a value in a binary tree
int searchBT(struct BTNode* root, int value, int* counter) {
    if (root == NULL)
        return 0;

    (*counter)++;
    if (root->data == value)
        return 1;
    else if (value < root->data)
        return searchBT(root->left, value, counter);
    else
        return searchBT(root->right, value, counter);
}

// Function to search for a value in a binary search tree
int searchBST(struct BSTNode* root, int value, int* counter) {
    if (root == NULL)
        return 0;

    (*counter)++;
    if (root->data == value)
        return 1;
    else if (value < root->data)
        return searchBST(root->left, value, counter);
    else
        return searchBST(root->right, value, counter);
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Number of elements in the trees
    int numElements = 100;

    // Populate the binary tree with random values
    struct BTNode* btRoot = NULL;
    for (int i = 0; i < numElements; i++) {
        int value = rand() % 1000; // Random value between 0 and 999
        btRoot = insertBTNode(btRoot, value);
    }

    // Populate the binary search tree with the same random values
    struct BSTNode* bstRoot = NULL;
    for (int i = 0; i < numElements; i++) {
        int value = rand() % 1000; // Random value between 0 and 999
        bstRoot = insertBSTNode(bstRoot, value);
    }

    // Perform searches and count comparisons for binary tree and binary search tree
    int btCounter = 0;
    int bstCounter = 0;
    int searchValue = rand() % 1000; // Random value between 0 and 999
    searchBT(btRoot, searchValue, &btCounter);
    searchBST(bstRoot, searchValue, &bstCounter);

    // Display the number of comparisons
    printf("Search value: %d\n", searchValue);
    printf("Comparisons in Binary Tree: %d\n", btCounter);
    printf("Comparisons in Binary Search Tree: %d\n", bstCounter);

    return 0;
}
