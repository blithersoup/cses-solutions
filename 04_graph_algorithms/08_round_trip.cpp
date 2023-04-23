#include "bits/stdc++.h"
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, a, b, nodes, edges, cur; cin >> n >> m;

  unordered_map<int, vector<int>> graph;



  vector<bool> visited (n + 1, 0);

  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      queue<int> q;
      q.push(i);
      nodes = 0; edges = 0;
      while (!q.empty()) {
        nodes++;
        cur = q.front(); q.pop();
        if (visited[cur]) {
          if (findpath(cur)) {
            return 0;
          }
        }
        else {
          visited[cur] = true;
          edges += graph[cur].size();
          for (int edge : graph[cur]) {
            q.push(edge);
          } 
        }
      }
    }
  }
}
