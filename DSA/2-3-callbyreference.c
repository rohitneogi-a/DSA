#include <stdio.h>

// Function to update array values using Call by Reference
void updateArray(int arr[], int size) {
    printf("Array elements in the function before update:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Update array elements
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }

    printf("Array elements in the function after update:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Declare and initialize an array
    int myArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    // Print array elements before passing to the function
    printf("Array elements in the main function before update:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    // Call the function and pass the array using Call by Reference
    updateArray(myArray, size);

    // Print array elements after the function call
    printf("Array elements in the main function after update:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    return 0;
}
