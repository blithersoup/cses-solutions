#include "bits/stdc++.h"
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, a, b;
  cin >> n >> m;

  unordered_map<int, set<int>> graph;
  vector<int> teams(n + 1, 0);

  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    graph[a].emplace(b);
    graph[b].emplace(a);
  }

  queue<int> q;

  int next, j;

  for (int i = 1; i <= n; i++) {
    if (!teams[i]) {
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        j = q.front(); q.pop();
        next = 2;
        if (teams[j] == 2)
          next = 1;
        else
          teams[i] = 1;

        for (auto x : graph[j]) {
          if (teams[x] == teams[j]) {
            cout << "IMPOSSIBLE\n";
            return 0;
          }
          if (!teams[x]) {
            teams[x] = next;
            q.push(x);
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << teams[i] << " ";
  cout << "\n";
}
