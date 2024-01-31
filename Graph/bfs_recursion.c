#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// Undirected Graph

typedef struct Graph_t
{
  int V;
  bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Constructor
Graph *Graph_create(int V)
{
  Graph *g = malloc(sizeof(Graph));
  g->V = V;

  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      g->adj[i][j] = false;
    }
  }

  return g;
}

void Graph_destroy(Graph *g) { free(g); }

void Graph_addEdge(Graph *g, int v, int w)
{
  g->adj[v][w] = true;
}

void BFS_recursive(Graph *g, int s, bool visited[MAX_VERTICES], int queue[MAX_VERTICES], int front, int rear)
{
  if (front == rear)
    return;
  s = queue[front++];
  printf("%d ", s);

  for (int adjacent = 0; adjacent < g->V; adjacent++)
  {
    if (g->adj[s][adjacent] && !visited[adjacent])
    {
      visited[adjacent] = true;
      queue[rear++] = adjacent;
    }
  }

  BFS_recursive(g, s, visited, queue, front, rear);
}

void Graph_BFS(Graph *g, int s)
{
  bool visited[MAX_VERTICES];
  for (int i = 0; i < g->V; i++)
  {
    visited[i] = false;
  }

  int queue[MAX_VERTICES];
  int front = 0, rear = 0;

  visited[s] = true;
  queue[rear++] = s;

  BFS_recursive(g, s, visited, queue, front, rear);
}

void printGraph(Graph *g)
{
  for (int i = 0; i < g->V; i++)
  {
    for (int j = 0; j < g->V; j++)
    {
      printf("%d ", g->adj[i][j]);
    }
    printf("\n");
  }
}

void BFS_LevelwisePrint(Graph *g, int s)
{
  int level[MAX_VERTICES];
  bool visited[MAX_VERTICES];
  int queue[MAX_VERTICES];
  int front = 0, rear = 0;

  for (int i = 0; i < g->V; i++)
  {
    visited[i] = false;
    level[i] = -1;
  }

  visited[s] = true;
  level[s] = 0;
  queue[rear++] = s;

  while (front != rear)
  {
    int v = queue[front++];
    printf("Vertex: %d, Level: %d\n", v, level[v]);

    for (int i = 0; i < g->V; i++)
    {
      if (g->adj[v][i] && !visited[i])
      {
        visited[i] = true;
        level[i] = level[v] + 1;
        queue[rear++] = i;
      }
    }
  }
}

int main()
{
  // Graph 1
  Graph *g = Graph_create(6);
  Graph_addEdge(g, 0, 1);
  Graph_addEdge(g, 0, 2);
  Graph_addEdge(g, 1, 3);
  Graph_addEdge(g, 2, 4);
  Graph_addEdge(g, 3, 4);
  Graph_addEdge(g, 4, 5);

  printGraph(g);

  printf("Following is Breadth First Traversal (starting from vertex 2) \n");
  Graph_BFS(g, 1);

  printf("\n");

  BFS_LevelwisePrint(g, 1);
  Graph_destroy(g);

  return 0;
}

//