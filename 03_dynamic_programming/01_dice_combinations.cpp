#include <iostream>
#include <vector>

using namespace std;

#define ll long long


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll mod = 1000000007;

  int n; cin >> n;

  vector<ll> v ( n + 1, 0 );
  v[0] = 1;
  
  for (ll i = 1; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      if ((i - j >= 0) and (v[i - j])) {
        v[i] += v[i - j];
        v[i] %= mod;
      }
    }
  }

  cout << v[n] << "\n";
}
