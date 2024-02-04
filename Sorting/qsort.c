#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

void sort(int a[], int n)
{
  qsort(a, n, sizeof(int), compare);
  printf("Sorted array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
}

int main()
{
  printf("Enter size: ");
  int n;
  scanf("%d", &n);
  int a[n];
  printf("Enter array elements: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  sort(a, n);
  return 0;
}