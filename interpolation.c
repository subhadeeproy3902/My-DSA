#include <stdio.h>
#include <stdlib.h>

int interpolation(int a[], int n, int x)
{
  int low = 0, high = n - 1;
  while (low <= high && x >= a[low] && x <= a[high])
  {
    if (low == high)
    {
      if (a[low] == x)
        return low;
      return -1;
    }
    int pos = low + (((double)(high - low) / (a[high] - a[low])) * (x - a[low]));
    if (a[pos] == x)
      return pos;
    if (a[pos] < x)
      low = pos + 1;
    else
      high = pos - 1;
  }
  return -1;
}


int main(){
    printf("Enter size: ");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements in sorted order: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    printf("Enter number to search: ");
    int x;
    scanf("%d", &x);
    
    int y = interpolation(a, n, x);
    if (y == -1) printf("Not found");
    else printf("Found at: %d", y);
    return 0;
}