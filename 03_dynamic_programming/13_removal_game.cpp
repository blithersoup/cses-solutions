#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<ll> v (n);
  for (int i = 0; i < n; i++) cin >> v[i];
  
  vector<vector<ll>> dp (n, (vector<ll> (n, 0)));


  for (int i = 0; i < n; i++) {
    dp[i][i] = v[i];
  } 

  for (int r = 1; r < n; r++) {
    for (int l = r - 1; l >= 0; l--) {
      dp[l][r] = max(v[l] - dp[l + 1][r], v[r] - dp[l][r - 1]);
    }
  }

  cout << (accumulate(v.begin(), v.end(), 0LL) + dp[0][n - 1]) / 2 << "\n"; 
  
}
