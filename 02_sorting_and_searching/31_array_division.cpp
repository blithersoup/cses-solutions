#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

#define ll long long

int main() {
  ll n, k; cin >> n >> k;

  vector<ll> v (n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  ll i = 0, j = accumulate(v.begin(), v.end(), 0LL), mid;
  ll ans = j;

  auto possible = [&](ll in) {
    ll _k = 0, sum = 0;
    for (auto &x : v) {
      if (x > mid) return false;
      sum += x;
      if (sum > in) {
        _k++;
        sum = x;
      } 
    }
    if (sum > 0) _k++;
    return _k <= k;
  };

  
  while (i <= j) {
    mid = (i + j) / 2;
    if (possible(mid)) {
      ans = mid;
      j = mid - 1;
    }
    else {
      i = mid + 1;
    }
  }

  cout << ans << "\n";
}
