# [Graph](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/)

For Undirected Graph:
```
void Graph_addEdge(Graph *g, int v, int w) {
  g->adj[v][w] = true;
  g->adj[w][v] = true;
}
```

For Directed Graph:
```
void Graph_addEdge(Graph *g, int v, int w) {
  g->adj[v][w] = true;
}
```

### Graph 1:

```  
        1
      /   \
     2     6
    / \   / \
   3   4 7   9
      /   \
     5 --- 8

  Graph *g = Graph_create(9);
  Graph_addEdge(g, 0, 1);
  Graph_addEdge(g, 0, 5);
  Graph_addEdge(g, 1, 2);
  Graph_addEdge(g, 1, 3);
  Graph_addEdge(g, 3, 4);
  Graph_addEdge(g, 4, 7);
  Graph_addEdge(g, 5, 6);
  Graph_addEdge(g, 5, 8);
  Graph_addEdge(g, 6, 7);
```

### Graph 1 Adjacency Matrix:

```
{
  {0, 1, 0, 0, 0, 1, 0, 0, 0},
  {1, 0, 1, 1, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 1, 0},
  {1, 0, 0, 0, 0, 0, 1, 0, 1},
  {0, 0, 0, 0, 0, 1, 0, 1, 0},
  {0, 0, 0, 0, 1, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0, 0}
}
```

### Graph 2:

```
      1 -- > 3
     ^       |  
    /        |
  0          |
    \        +
     > 2 --> 4
```

