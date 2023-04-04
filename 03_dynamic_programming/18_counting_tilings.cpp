#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main() {
  ll n, m; cin >> n >> m;
  ll mod = 1000000007LL;
  
  vector<pair<ll, ll>> dp (1 << n, {0, 0});
  dp[0] = {1, 0};
  
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      for (int mask = 0; mask < (1 << n); mask++) {
        dp[mask].second = dp[mask ^ (1 << i)].first;
        if (i and !(mask & (1 << i)) and !(mask & (1 << (i - 1))))
            dp[mask].second += dp[mask ^ (1 << (i - 1))].first;
        dp[mask].second %= mod;
      }
      for (int mask = 0; mask < (1 << n); mask++) 
        dp[mask].first = dp[mask].second;
      
    }
  } 
  
  cout << dp[0].first << "\n";
}

