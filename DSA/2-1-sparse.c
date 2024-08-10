#include <stdio.h>

// Function to read a 2D array and represent it as a sparse matrix
void readAndPrintSparseMatrix() {
    int rows, cols;

    // Input the dimensions of the matrix
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Input the 2D array
    int matrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Count the number of non-zero elements
    int nonZeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    // Create a sparse matrix
    int sparseMatrix[nonZeroCount + 1][3];
    sparseMatrix[0][0] = rows;
    sparseMatrix[0][1] = cols;
    sparseMatrix[0][2] = nonZeroCount;

    int k = 1; // Counter for the sparse matrix rows
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    // Print the sparse matrix
    printf("\nSparse Matrix Representation:\n");
    for (int i = 0; i <= nonZeroCount; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", sparseMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    readAndPrintSparseMatrix();
    return 0;
}
