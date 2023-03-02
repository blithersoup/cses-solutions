#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m, x;

  cin >> n >> m;

  multiset<int> h;
  for (int i = 0; i < n; i++) {
    cin >> x;
    h.emplace(x);
  }

  multiset<int>::iterator it;
  
  for (int i = 0; i < m; i++) {
    cin >> x;

    it = h.upper_bound(x);

    if (it == h.begin()) {
      cout << "-1\n";
    }
    else {
      cout << *(--it) << "\n";
      h.erase(it);
    }
  }
}
