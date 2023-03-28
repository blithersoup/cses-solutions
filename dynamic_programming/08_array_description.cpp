#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

#define ll long long
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll mod = 1000000007;

  int n, m, x; cin >> n >> m;

  vector<vector<ll>> memo (n, vector<ll> (m + 2, 0));
  cin >> x;
  if (x) memo[0][x] = 1;

  else for (int i = 1; i <= m; i++) {
    memo[0][i] = 1;
  }

  for (int i = 1; i < n; i++) {
    cin >> x;

    if (x) {
      memo[i][x] += memo[i - 1][x - 1];
      memo[i][x] += memo[i - 1][x];
      memo[i][x] += memo[i - 1][x + 1];
      memo[i][x] %= mod;
    }
    else for (int j = 1; j <= m; j++) {
      memo[i][j] += memo[i - 1][j - 1];
      memo[i][j] += memo[i - 1][j];
      memo[i][j] += memo[i - 1][j + 1];
      memo[i][j] %= mod;
    }
  }

  cout << accumulate(memo[n - 1].begin(), memo[n - 1].end(), 0LL) % mod << "\n";
  
}
