#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Input the initial number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array of n elements using calloc
    int *dynamicArray = (int *)calloc(n, sizeof(int));

    // Check if memory allocation is successful
    if (dynamicArray == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    // Input elements into the initially allocated array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &dynamicArray[i]);
    }

    // Display the elements before reallocation
    printf("Elements in the initially allocated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Input the new size for reallocation
    int newSize;
    printf("Enter the new size for reallocation: ");
    scanf("%d", &newSize);

    // Reallocate memory using realloc
    dynamicArray = (int *)realloc(dynamicArray, newSize * sizeof(int));

    // Check if reallocation is successful
    if (dynamicArray == NULL) {
        printf("Memory reallocation failed. Exiting program.\n");
        return 1;
    }

    // Input elements into the reallocated array
    printf("Enter %d elements after reallocation:\n", newSize);
    for (int i = 0; i < newSize; i++) {
        scanf("%d", &dynamicArray[i]);
    }

    // Display the elements after reallocation
    printf("Elements in the reallocated array:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(dynamicArray);

    return 0;
}
