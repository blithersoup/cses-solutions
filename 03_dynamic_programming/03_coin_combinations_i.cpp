#include <iostream>
#include <vector>

using namespace std;

#define ll long long


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll mod = 1000000007;

  int n, x; cin >> n >> x;

  vector<ll> coins (n);
  for (int i = 0; i < n; i++) cin >> coins[i];

  vector<ll> sums ( x + 1, 0 );
  sums[0] = 1;
  
  for (ll i = 1; i <= x; i++) {
    for (auto c : coins) {
      if ((i - c >= 0) and (sums[i - c])) {
        sums[i] += sums[i - c];
        sums[i] %= mod;
      }
    }
  }

  cout << sums[x] << "\n";
}
