#include <iostream>
#include <stack>

using namespace std;

const int N = 11;

int A[N][N] = {
    {0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
    {
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
    },
    {
        0,
        0,
        0,
        1,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
    },
    {
        1,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    },
    {
        0,
        1,
        0,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        1,
    },
    {
        0,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
        1,
    },
    {
        0,
        0,
        1,
        0,
        1,
        0,
        0,
        1,
        0,
        0,
        0,
    },
    {
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        0,
        1,
        1,
        0,
    },
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    {
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        1,
        0,
        0,
    },
    {
        0,
        0,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
    },
};

void DFS(int start)
{
  stack<int> s;
  bool visited[N] = {false};

  s.push(start);
  visited[start] = true;

  while (!s.empty())
  {
    int current = s.top();
    s.pop();
    cout << current << " ";

    for (int i = 0; i < N; ++i)
    {
      if (A[current][i] == 1 && !visited[i])
      {
        s.push(i);
        visited[i] = true;
      }
    }
  }
}

int main()
{
  cout << "DFS starting from node 0:" << endl;
  DFS(0);

  return 0;
}
