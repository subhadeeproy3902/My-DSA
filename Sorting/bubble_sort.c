#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  printf("Sorted array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
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

  bubbleSort(arr, n);
  return 0;
}