#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int reqs[48];
bool visited[9][9];

void bfs(int i, int j, int &size, int &ret) {

  if (size == 48) {
    if ((i == 7) and (j == 1)) {
      ret++;
    }
    return;
  }

  if ((i == 7) and (j == 1)) {
    return;
  }

  bool candown = !visited[i + 1][j];
  bool canup = !visited[i - 1][j];
  bool canright = !visited[i][j + 1];
  bool canleft = !visited[i][j - 1];

  if (((!canleft) and (!canright) and canup and candown) or
      ((!canup) and (!candown) and canleft and canright)) {
    return;
  }

  visited[i][j] = true;

  if (reqs[size] != -1) {
    size++;
    if (reqs[size - 1] == 0 and canleft) {
      bfs(i, j - 1, size, ret);
    } 
    else if (reqs[size - 1] == 1 and canright) {
      bfs(i, j + 1, size, ret);
    } 
    else if (reqs[size - 1] == 2 and canup) {
      bfs(i - 1, j, size, ret);
    } else if (reqs[size - 1] == 3 and candown) {
      bfs(i + 1, j, size, ret);
    }
    size--;
    visited[i][j] = false;
    return;
  }
  size++;

  if (candown) {
    bfs(i + 1, j, size, ret);
  }
  if (canup) {
    bfs(i - 1, j, size, ret);
  }
  if (canright) {
    bfs(i, j + 1, size, ret);
  }
  if (canleft) {
    bfs(i, j - 1, size, ret);
  }

  size--;
  visited[i][j] = false;
}

int main() {
  string s;
  cin >> s;

  unordered_map<char, int> m{{'L', 0}, {'R', 1}, {'U', 2}, {'D', 3}};


  for (int i = 0; i < 48; i++) {
    if (s[i] != '?') {
      reqs[i] = m[s[i]];
    }
    else {
      reqs[i] = -1;
    }
  }

  for (int i = 0; i < 9; i++) {
    visited[0][i] = true;
    visited[8][i] = true;
  }
  for (int i = 1; i < 8; i++) {
    visited[i][0] = true;
    visited[i][8] = true;
  }
  for (int i = 1; i < 8; i++) {
    for (int j = 1; j < 8; j++) {
      visited[i][j] = false;
    }
  }

  int size = 0, ret = 0;

  bfs(1, 1, size, ret);

  cout << ret << "\n";
}
