//DFS traversal of a graph

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> adj[N], v;
vector<bool> vis(N);


void dfs(int s)
{
  vis[s] = true;
  v.push_back(s);
  for (int i = 0; i < adj[s].size(); i++)
  {
    int x = adj[s][i];
    if (vis[x] == true) continue;
    dfs(x);
  }
}


void dfs_iterative(int s)
{
  stack<int> S;
  S.push(s);
  vis[s] = true;
  while (!S.empty())
  {
    int p = S.top();
    S.pop();
    for (int i = 0; i < adj[p].size(); i++)
    {
      int x = adj[p][i];
      if (vis[x] == true) continue;
      S.push(x);
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

  for (int i = 1; i <= n; i++)
  {
    if (vis[i] == true) continue;
    dfs(i);
  }

  for (int i = 0; i < v.size(); i++)  //DFS traversal
  cout << v[i] << " "; cout << endl;

  return 0;
}
