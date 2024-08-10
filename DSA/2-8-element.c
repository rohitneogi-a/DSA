#include <stdio.h>
#include <stdlib.h>

// Function to search for an element in the array
int searchElement(int *arr, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

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

    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &dynamicArray[i]);
    }

    int key;

    // Input the element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Search for the element in the array
    int index = searchElement(dynamicArray, n, key);

    // Display the result
    if (index != -1) {
        printf("Element %d found at index %d.\n", key, index);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    // Free the dynamically allocated memory
    free(dynamicArray);

    return 0;
}
