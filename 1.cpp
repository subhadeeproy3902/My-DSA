#include <bits/stdc++.h>
using namespace std;

int main()
{
  // your code goes here
  int t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      ans.push_back(x);
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
      result ^= ans[i];
    }
    cout << result;
  }
  return 0;
}
