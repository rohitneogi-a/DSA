#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array of n elements
    int *dynamicArray = (int *)malloc(n * sizeof(int));

    // Check if memory allocation is successful
    if (dynamicArray == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    // Input elements into the dynamically allocated array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &dynamicArray[i]);
    }

    // Display the elements
    printf("Elements in the dynamically allocated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(dynamicArray);

    return 0;
}
