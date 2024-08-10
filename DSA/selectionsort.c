#include<stdio.h>
void printarray(int *a, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}
void selectionsort(int* a , int n){
  int i,j,temp , min;
  for ( i = 0; i < n-1; i++)
  {
    min=i;
    printf("Iteration %d: ", i + 1);
    for ( j = i+1; j < n; j++)
    {
      if (a[j]<a[min])
      {
        min = j;
      }
      
    }
    temp =a[i];
    a[i] = a[min];
    a[min] = temp;
    
    

    printarray(a, n);
  }
  

}
int main(){
  int a[] = {27, 15, 39, 21, 28, 70};
  int n = 6;
  printf("Original Array::");
  printarray(a, n);
  selectionsort(a, n);
  printf("Sorted Array::");
  printarray(a, n);
  return 0;
}