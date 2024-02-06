#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *queue[100];
int front = -1, rear = -1;

void bfs(int arr[9][9], int visited[], int start, int n)
{
  visited[start] = 1;
  printf("%d ", start);
  for (int i = 0; i < n; i++)
  {
    if (arr[start][i] == 1 && visited[i] == 0)
    {
      queue[++rear] = i;
      visited[i] = 1;
    }
  }
  if (front <= rear)
  {
    bfs(arr, visited, queue[++front], n);
  }
}

int main()
{
  int arr[9][9] = {
      {0, 1, 0, 0, 0, 1, 0, 0, 0},
      {1, 0, 1, 1, 0, 0, 0, 0, 0},
      {0, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 1, 0, 0, 1, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0, 1, 0},
      {1, 0, 0, 0, 0, 0, 1, 0, 1},
      {0, 0, 0, 0, 0, 1, 0, 1, 0},
      {0, 0, 0, 0, 1, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 1, 0, 0, 0}};
  int visited[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  bfs(arr, visited, 0, 9);
  return 0;
}