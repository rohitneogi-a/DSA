#include <stdio.h>

void printarray(int *a, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void bubblesort(int *a, int n)
{
  int i, j, temp;
  for ( i = 0; i < n - 1; i++)
  {
    printf("Iteration %d: ", i + 1);
    for ( j = 0; j < n - 1 - i; j++)
    {
      if (a[j] > a[j + 1])
      {
         temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
    printarray(a, n);
  }
}

int main()
{
  int a[] ={27, 15, 39, 21, 28, 70};
  int n = 6;
  printf("Original Array::");
  printarray(a, n);
  bubblesort(a, n);
  printf("Sorted Array::");
  printarray(a, n);

  return 0;
}