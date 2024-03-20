#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 50

typedef struct Graph
{
  int V;
  bool adj[MAX_VERTICES][MAX_VERTICES];
} graph;

graph *createGraph(int V)
{
  graph *g = malloc(sizeof(graph));
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

void graph_destroy(graph *g)
{
  free(g);
}

void graph_addEdge(graph *g, int v, int w)
{
  g->adj[v][w] = true;
  g->adj[w][v] = true;
}

void graph_BFS(graph *g, int s)
{
  bool visited[MAX_VERTICES] = {false};
  int queue[MAX_VERTICES];
  int front = 0, rear = 0;

  visited[s] = true;
  queue[rear++] = s;

  while (front != rear)
  {
    s = queue[front++];
    printf("%d ", s);
    for (int i = 0; i < g->V; i++)
    {
      if (g->adj[s][i] && !visited[i])
      {
        visited[i] = true;
        queue[rear++] = i;
      }
    }
  }
}

int main()
{

  int vertices, edges;
  printf("Enter number of vertices: ");
  scanf("%d", &vertices);
  graph *g = createGraph(vertices);
  printf("Enter number of edges: ");
  scanf("%d", &edges);
  for (int i = 0; i < edges; i++)
  {
    int v, w;
    printf("Enter edge %d (format: source destination): ", i + 1);
    scanf("%d"
          "%d",
          &v, &w);
    graph_addEdge(g, v, w);
  }

  int start;
  printf("Enter starting vertex: ");
  scanf("%d", &start);
  printf("BFS traversal starting from vertex %d \n", start);
  graph_BFS(g, start);
  graph_destroy(g);

  return 0;
}
