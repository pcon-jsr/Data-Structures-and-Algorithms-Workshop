//Weighted Disjoint Set Union with path compression.


#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> parent(N), cnt(N, 0);

int get_parent(int n)
{
  while (n != parent[n])
  {
    parent[n] = parent[parent[n]];
    n = parent[n];
  }
  return n;
}

int main(int argc, char const *argv[]) {

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  parent[i] = i;

  while (m--)
  {
    int a, b;
    cin >> a >> b;
    int x = get_parent(a), y = get_parent(b);
    if (x == y) continue;

    if (cnt[x] < cnt[y])
    {
      parent[x] = parent[y];
      cnt[y] += cnt[x];
    }
    else
    {
      parent[y] = parent[x];
      cnt[x] += cnt[y];
    }
  }

  return 0;
}
