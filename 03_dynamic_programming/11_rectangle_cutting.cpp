#include "bits/stdc++.h"
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b; cin >> a >> b;
   
  vector<vector<int>> dp (a + 1, vector<int> (b + 1, 25000));

  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      if (i == j) dp[i][j] = 0;
      else {
        for (int x = 1; x < i; x++) {
          dp[i][j] = min(dp[i][j], 1 + dp[x][j] + dp[i - x][j]);
        }
        for (int x = 1; x < j; x++) {
          dp[i][j] = min(dp[i][j], 1 + dp[i][x] + dp[i][j - x]);
        }
      }
    }
  }

  cout << dp[a][b] << "\n";
}
