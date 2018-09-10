//Shortest distance from a single node to every other nodes in the graph.

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, inf = 1e9;
vector<pair<int, int> > v[N];
vector<int> dist(N, inf);
vector<bool> vis(N);

void dj(int n)
{
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
  q.push(make_pair(0, n));
  dist[n] = 0;
  while (!q.empty())
  {
    pair<int, int> p = q.top();
    q.pop();
    int x = p.second;
    if (vis[x] == true) continue;
    vis[x] = true;
    for (int i = 0; i < v[x].size(); i++)
    {
      int a = v[x][i].first, b = v[x][i].second;
      if ( dist[b] > a + dist[x] )
      {
        dist[b] = a + dist[x];
        q.push(make_pair( dist[b], b ));
      }
    }
  }
}

int main() {

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back(make_pair(c, b));
    v[b].push_back(make_pair(c, a));
  }

  dj(1);
  for (int i = 2; i <= n; i++)  //Shortest distance from 1 to all other nodes.
  cout << dist[i] << " "; cout << endl;

    return 0;
}
