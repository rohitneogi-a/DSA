#include <stdio.h>

int fibo(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}

int main() {
    int n;
    printf("Enter Number: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", fibo(i)); // Added a space after each number
    }
    printf("\n");
    return 0;
}

