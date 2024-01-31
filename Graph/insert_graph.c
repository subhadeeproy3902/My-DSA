#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphNode
{
  int vertex;
  int adj[MAX_VERTICES][MAX_VERTICES];
} GraphNode;

GraphNode *create(int vertex)
{
  GraphNode *g = (GraphNode *)malloc(sizeof(GraphNode));
  g->vertex = vertex;
  for (int i = 0; i < MAX_VERTICES; i++)
  {
    for (int j = 0; j < MAX_VERTICES; j++)
    {
      g->adj[i][j] = 0;
    }
  }
  return g;
}

void insert_edge(GraphNode *g, int u, int v)
{
  g->adj[u][v] = 1;
  g->adj[v][u] = 1;
}

void print_graph(GraphNode *g)
{
  for (int i = 0; i < g->vertex; i++)
  {
    for (int j = 0; j < g->vertex; j++)
    {
      printf("%d ", g->adj[i][j]);
    }
    printf("\n");
  }
}

int main(void)
{
  GraphNode *g = create(4);
  insert_edge(g, 0, 1);
  insert_edge(g, 0, 2);
  insert_edge(g, 0, 3);
  insert_edge(g, 1, 2);
  insert_edge(g, 2, 3);
  print_graph(g);
  return 0;
}