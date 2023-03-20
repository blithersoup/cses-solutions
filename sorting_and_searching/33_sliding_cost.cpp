#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

#define ll long long

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, k, x;
  cin >> n >> k;

  multiset<ll> l, r;

  vector<ll> v(n);

  for (int i = 0; i < n; i++) {
    cin >> x;
    v[i] = x;
  }

  if (k == 1) {
    for (auto p : v) {
      cout << p << " ";
    }
    cout << "\n";
    return 0;
  }

  for (int i = 0; i < k; i++) {
    r.emplace(v[i]);
  }

  for (int i = 0; i < (k / 2); i++) {
    l.emplace(*r.begin());
    r.erase(r.begin());
  }

  bool even = ((k % 2) == 0);

  n -= k;
  ll med;
  med = *r.begin();
  if (even)
    med = min(med, *(--l.end()));

  cout << accumulate(v.begin(), v.begin() + k, 0LL, [&med](ll a, ll b) {
    return a + abs(med - b);
  }) << " ";

  for (int i = 0; i < n; i++) {
    if (v[i] < *r.begin()) {
      l.erase(l.find(v[i]));
      r.emplace(v[i + k]);
      l.emplace(*r.begin());
      r.erase(r.begin());
    } else {
      r.erase(r.find(v[i]));
      r.emplace(v[i + k]);
      r.emplace(*(--l.end()));
      l.erase(--l.end());
      l.emplace(*r.begin());
      r.erase(r.begin());
    }

    med = *r.begin();
    if (even)
      med = min(med, *(--l.end()));
    cout << accumulate(v.begin() + i + 1, v.begin() + i + k + 1, 0LL,
                       [&med](ll a, ll b) { return a + abs(med - b); })
         << " ";
  }
}
