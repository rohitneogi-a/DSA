#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void readMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int firstMatrix[MAX_ROWS][MAX_COLS], int secondMatrix[MAX_ROWS][MAX_COLS],
                      int resultMatrix[MAX_ROWS][MAX_COLS], int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input dimensions of the first matrix
    printf("Enter dimensions of the first matrix (rows and columns): ");
    scanf("%d %d", &rows1, &cols1);

    // Input dimensions of the second matrix
    printf("Enter dimensions of the second matrix (rows and columns): ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible!\n");
        return 1;
    }

    int firstMatrix[MAX_ROWS][MAX_COLS], secondMatrix[MAX_ROWS][MAX_COLS], resultMatrix[MAX_ROWS][MAX_COLS];

    // Input elements of the first matrix
    printf("For the first matrix:\n");
    readMatrix(firstMatrix, rows1, cols1);

    // Input elements of the second matrix
    printf("For the second matrix:\n");
    readMatrix(secondMatrix, rows2, cols2);

    // Multiply the matrices
    multiplyMatrices(firstMatrix, secondMatrix, resultMatrix, rows1, cols1, rows2, cols2);

    // Display the result
    printf("Result of matrix multiplication:\n");
    displayMatrix(resultMatrix, rows1, cols2);

    return 0;
}
