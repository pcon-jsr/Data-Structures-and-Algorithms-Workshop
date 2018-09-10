//BFS traversal, level and number of connected components of a graph.

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> adj[N], level(N);
vector<bool> vis(N);
vector<int> v;

void bfs(int s)
{
  queue<int> q;
  q.push(s);
  vis[s] = true;
  level[s] = 0;
  while (!q.empty())
  {
    int p = q.front();
    q.pop();
    v.push_back(p);
    for (int i = 0; i < adj[p].size(); i++)
    {
      int x = adj[p][i];
      if (vis[x] == true) continue;
      level[x] = level[p] + 1;
      q.push(x);
      vis[x] = true;
    }
  }
}


int main(int argc, char const *argv[]) {

  int n, m;
  cin >> n >> m;  //n and m are number of nodes and edges resp.
  while (m--)
  {
    int a, b;
    cin >> a >> b;  //(a, b) denotes a bidirectional edge between nodes a and b.
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int num_connnected_comp = 0;
  for (int i = 1; i <= n; i++)
  {
    if (vis[i] == 1) continue;
    bfs(i);
    num_connnected_comp++;
  }

  cout << num_connnected_comp << endl;  //Number of connected component

  for (int i = 0; i < v.size(); i++)  //BFS traversal
  cout << v[i] << " "; cout << endl;

  for (int i = 1; i <= n; i++)  //Level of each node
  cout << level[i] << " "; cout << endl;

  return 0;
}
