//2.3
#include <stdio.h>

#define MAX_SIZE 100

// Function to display the binary tree level-wise
void displayTreeLevelWise(int tree[], int n) {
    int i = 0;
    int level = 1;
    int nodesInLevel = 1;

    while (i < n) {
        printf("Level %d: ", level);
        for (int j = 0; j < nodesInLevel && i < n; j++) {
            printf("%d ", tree[i]);
            i++;
        }
        printf("\n");
        level++;
        nodesInLevel *= 2;
    }
}

int main() {
    int tree[MAX_SIZE] = {1, 2, 3, 4, 5, 6};

    int n = sizeof(tree) / sizeof(tree[0]);

    // Display the binary tree level-wise
    printf("Binary Tree Level-wise:\n");
    displayTreeLevelWise(tree, n);

    return 0;
}
