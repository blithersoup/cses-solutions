#include "bits/stdc++.h"
using namespace std;

bool visited[1000][1000];


int xdirs[4] = { -1, 1, 0, 0 };
int ydirs[4] = { 0, 0, 1, -1 };
string dirs = "UDRL";


int main() {
  int n, m; cin >> n >> m;
  
  vector<vector<int>> prev (n, vector<int> (m, 0));
  vector<string> graph (n);
  for (auto &x : graph) cin >> x;

  pair<int, int> start, end;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (graph[i][j] == 'A') start = { i, j };
      if (graph[i][j] == 'B') end = { i, j };
    }
  }

  queue<pair<int, int>> q;
  q.push(start);
  
  pair<int, int> cur;
  int i, j;

  while (!q.empty()) {
    cur = q.front();
    q.pop();

    for (int x = 0; x < 4; x++) {
      i = cur.first + xdirs[x];
      j = cur.second + ydirs[x];
      if (i < 0 or i >= n or j < 0 or j >= m) continue;
      if (graph[i][j] == '#') continue;
      if (visited[i][j]) continue;
      prev[i][j] = x;
      visited[i][j] = true;
      q.push({ i, j });
    }
  }

  if (!visited[end.first][end.second]) {
    cout << "NO\n";
    return 0;
  }

  string ret;

  i = end.first;
  j = end.second;
  int x;
  while (graph[i][j] != 'A') {
    x = prev[i][j];
    ret.push_back(dirs[x]);
    i -= xdirs[x];
    j -= ydirs[x];
  }

  reverse(ret.begin(), ret.end());

  cout << "YES\n" << ret.size() << "\n" << ret << "\n";
}
