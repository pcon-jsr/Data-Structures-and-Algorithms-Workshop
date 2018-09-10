#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<pair<int, pair<int, int> > > adj;
vector<int> p(N);

int get_parent(int n)
{
  while (n != p[n])
  {
    p[n] = p[p[n]];
    n = p[n];
  }
  return n;
}

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  p[i] = i;

  for (int i = 0; i < m; i++)
  {
    int a, b, c;  //edge between nodes a and b with weight c
    cin >> a >> b >> c;
    adj.push_back({c, {a, b}});
  }
  sort(adj.begin(), adj.end());

  int cnt = 0;
  for (int i = 0; i < m; i++)
  {
    int a = adj[i].second.second, b = adj[i].second.first;
    int x = get_parent(a), y = get_parent(b);
    if (x != y)
    {
      p[x] = y;
      cnt += adj[i].first;
    }
  }

  cout << cnt << endl;

  return 0;
}
