#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solve(int *col, int n, int row){
  int count = 0;
  if (row == n){
    return 1;
  }
  for (int column = 0; column < n; column++){
    if (!col[column]){
      col[column] = 1;
      count += solve(col, n, row + 1);
      col[column] = 0;
    }
  }
  return count;

}

int totalNRooks(int n){
  int *col = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++){
    col[i] = 0;
  }
  int result = solve(col, n, 0);
  free(col);
  return result;
}

int main(){
  int n = 4;
  printf("%d\n", totalNRooks(n));
  return 0;
}