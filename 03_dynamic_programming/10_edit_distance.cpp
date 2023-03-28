#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b; cin >> a >> b;

  int n = a.size(), m = b.size(), o;

  vector<vector<int>> v (n + 1, vector<int> (m + 1));

  for (int j = 0; j <= m; j++) v[0][j] = j;

  for (int i = 1; i <= n; i++) {
    v[i][0] = i;
    for (int j = 1; j <= m; j++) {
      o = a[i - 1] != b[j - 1];
      v[i][j] = min(v[i - 1][j], v[i][j - 1]) + 1;
      v[i][j] = min(v[i][j], v[i - 1][j - 1] + o);
    }
  }


  cout << v[n][m] << "\n";
}
