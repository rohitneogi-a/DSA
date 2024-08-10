#include <stdio.h>

void findLargestAndSecondLargest(int arr[], int size) {
    int largest, secondLargest;

    if (size < 2) {
        printf("Array size should be at least 2.\n");
        return;
    }

    largest = secondLargest = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    printf("Largest element: %d\n", largest);
    printf("Second largest element: %d\n", secondLargest);
}

int main() {
    int arr[] = {5, 8, 3, 1, 9, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    findLargestAndSecondLargest(arr, size);

    return 0;
}
