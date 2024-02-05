#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}

void sort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && key < arr[j])
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
  printf("Sorted array: ");
  print(arr, n);
}

int main()
{
  int n;
  printf("Enter size: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter elements: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  printf("Original Array: ");
  print(arr, n);

  sort(arr, n);
  return 0;
}