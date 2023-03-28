#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k, x;
  cin >> n >> m >> k;

  vector<int> a, b;

  for (int i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < m; i++) {
    cin >> x;
    b.push_back(x);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int j = 0, ret = 0;

  for (int i = 0; (i < n) and (j < m); i++) {
    while ((b[j] < (a[i] - k)) and (j < m)) {
      j++;
    }
    if (abs(b[j] - a[i]) <= k) {
      ret++;
      j++;
    }

  }
  cout << ret << "\n";
}
