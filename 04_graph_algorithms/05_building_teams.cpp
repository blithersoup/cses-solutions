#include "bits/stdc++.h"
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, a, b; cin >> n >> m;

  unordered_map<int, set<int>> graph;
  vector<int> teams (n + 1, 0);

  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    graph[a].emplace(b);
    graph[b].emplace(a);
  }

  queue<pair<int, int>> q;


  auto bfs = [&](pair<int, int> in) -> bool {
    int node = in.first, color = in.second;
    if (teams[node]) return true;
    int other = -color;
    for (int adj : graph[node]) {
      if (teams[adj] == color) return false;
      teams[adj] = other;
      q.push({adj, other});
    }
    return true;
  };
  
  for (int i = 1; i <= n; i++) {
    if (!teams[i]) {
      q.push({i, 1});
      while (!q.empty()) {
        if (!bfs(q.front())) {
          cout << "IMPOSSIBLE\n";
          return 0;
        }
        q.pop();
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ((teams[i] == 1) ? 1 : 2) << " ";
  }

}
