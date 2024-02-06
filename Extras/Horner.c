#include <stdio.h>
int horner(int[], int, int);
int horner(int arr[], int size, int xx)
{
  if (size == 0)
    return arr[0];
  return arr[size] + xx * horner(arr, size - 1, xx);
}
void main()
{
  int n, x;
  printf("Enter degree of polynomial : ");
  scanf("%d", &n);
  int a[n + 1];
  printf("Enter the value of x : ");
  scanf("%d", &x);
  for (int i = 0; i <= n; i++)
  {
    printf("Enter coefficient of x^%d :", n - i);
    scanf("%d", &a[i]);
  }
  int r = horner(a, n, x);
  printf("Result of polynomial expression is : %d", r);
}