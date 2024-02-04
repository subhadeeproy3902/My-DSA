#include <stdio.h>
#include <stdlib.h>

int visited[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int A[11][11] = {};

void DFS(int i) {
  printf("%d ", i);
  visited[i] = 1;
  for (int j = 0; j < 11; j++){
    if (A[i][j] == 1 && !visited[j]) DFS(j);
  }
}

int main() {
  DFS(0);
  return 0;
}