#include <stdio.h>
#include <stdlib.h>

struct Node * f = NULL;
struct Node * r = NULL;

struct Node {
  int data;
  struct Node * next;
};

void enqueueRecursive(int val) {
  struct Node * n = (struct Node * ) malloc(sizeof(struct Node));
  if (n == NULL) printf("Queue is Full\n");
  else {
    n -> data = val;
    n -> next = NULL;
    if (f == NULL) f = r = n;
    else {
      r -> next = n;
      r = n;
    }
  }
}

int dequeue() {
  int val = -1;
  struct Node * p = f;
  if (f == NULL) printf("Queue is Empty\n");
  else {
    f = f -> next;
    val = p -> data;
    free(p);
  }
  return val;
}

void BFS(int a[][9], int visited[], int start, int n) {
  int i = start, j;
  printf("%d ", i);
  visited[i] = 1;
  enqueueRecursive(i);
  while (f != NULL) {
    i = dequeue();
    for (j = 0; j < n; j++) {
      if (a[i][j] == 1 && visited[j] == 0) {
        printf("%d ", j);
        visited[j] = 1;
        enqueueRecursive(j);
      }
    }
  }
}

int main() {
  int visited[9] = {};
  int a[9][9] = {};
  BFS(a, visited, 0, 9);
  return 0;
}