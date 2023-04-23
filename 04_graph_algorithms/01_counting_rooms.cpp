#include "bits/stdc++.h"
using namespace std;

bool graph[1002][1002];
bool visited[1002][1002];

void dfs(int i, int j) {
  if (visited[i][j] or !graph[i][j]) return;
  visited[i][j] = true;
  dfs(i - 1, j);
  dfs(i + 1, j);
  dfs(i, j - 1);
  dfs(i, j + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m; cin >> n >> m;
  string s;

  for (int i = 1; i <= n; i++) {
    visited[i][0] = true;
    visited[i][m + 1] = true;
  }
  for (int j = 1; j <= m; j++) {
    visited[0][j] = true;
    visited[n + 1][j] = true;
  }

  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '.') graph[i][j + 1] = true;
    }
  }

  int ret = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (graph[i][j] and !visited[i][j]) {
        ret++;
        dfs(i, j);
      }
    }
  }

  cout << ret << "\n";


}
