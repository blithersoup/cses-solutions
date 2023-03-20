#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

bool enough (vector<ll> &v, ll &k, ll i) {
  ll ret = 0;
  for (auto& y : v) {
    ret += (i / y);
  }
  return (ret >= k);
}

int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> v (n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  
  ll i = 0, j = k * *min_element(v.begin(), v.end());

  for (ll b = j; b >= 1; b /= 2) {
    while (!enough(v, k, i + b)) {
      i += b;
    }
  }

  cout << i + 1 << "\n";
}
