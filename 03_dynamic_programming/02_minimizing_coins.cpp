#include <iostream>
#include <vector>

using namespace std;

#define ll long long


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x; cin >> n >> x;

  vector<ll> coins (n);
  for (int i = 0; i < n; i++) cin >> coins[i];

  vector<ll> sums ( x + 1, 10000000 );
  sums[0] = 0;
  
  for (ll i = 1; i <= x; i++) {
    for (auto c : coins) {
      if ((i - c >= 0) and (sums[i - c] < 10000000)) {
        sums[i] = min(sums[i], sums[i - c] + 1);
      }
    }
  }

  cout << ((sums[x] == 10000000) ? -1 : sums[x]) << "\n";
}
