#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int solve(int *col, int *diag, int *anti_diag, int n, int row)
{
  int count = 0;

  if (row == n)
  {
    return 1;
  }

  for (int column = 0; column < n; column++)
  {
    if (!col[column] && !diag[row + column] && !anti_diag[row - column + n - 1])
    {
      col[column] = diag[row + column] = anti_diag[row - column + n - 1] = 1;
      count += solve(col, diag, anti_diag, n, row + 1);
      col[column] = diag[row + column] = anti_diag[row - column + n - 1] = 0;
    }
  }

  return count;
}



int totalNQueens(int n)
{
  int *col = (int *)malloc(n * sizeof(int));
  int *diag = (int *)malloc((2 * n - 1) * sizeof(int));
  int *anti_diag = (int *)malloc((2 * n - 1) * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    col[i] = 0;
  }

  for (int i = 0; i < 2 * n - 1; i++)
  {
    diag[i] = 0;
    anti_diag[i] = 0;
  }

  int result = solve(col, diag, anti_diag, n, 0);

  free(col);
  free(diag);
  free(anti_diag);

  return result;
}


int main(){
  int n = 8;
  printf("%d\n", totalNQueens(n));
  return 0;
}