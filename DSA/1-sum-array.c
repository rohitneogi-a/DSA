#include <stdio.h>

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Array size must be greater than 0.\n");
        return 1;  
    }

    int arr[size];

    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    
    printf("Sum of array elements: %d\n", sum);

    return 0;
}
