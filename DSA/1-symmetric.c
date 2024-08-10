#include <stdio.h>

#define MAX_SIZE 10

// Function to read a matrix
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to check if a matrix is symmetric
int isSymmetric(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    if (rows != cols) {
        return 0; // A non-square matrix is not symmetric
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0; // If any element is different from its symmetric counterpart, matrix is not symmetric
            }
        }
    }

    return 1; // Matrix is symmetric
}

int main() {
    int rows, cols;

    // Input dimensions of the matrix
    printf("Enter dimensions of the matrix (rows and columns): ");
    scanf("%d %d", &rows, &cols);

    int matrix[MAX_SIZE][MAX_SIZE];

    // Input elements of the matrix
    readMatrix(matrix, rows, cols);

    // Check if the matrix is symmetric
    if (isSymmetric(matrix, rows, cols)) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }

    return 0;
}
