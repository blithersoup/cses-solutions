#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n, k, x;
  cin >> n >> k;

  multiset<int> l, r;

  vector<int> v(n);

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
  int med;
  med = *r.begin();
  if (even)
    med = min(med, *(--l.end()));
  cout << med << " ";

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

    cout << med << " ";
  }
}
