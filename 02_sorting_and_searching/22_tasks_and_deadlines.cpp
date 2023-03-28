#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define ll long long 

int main() {
  int n, a, b; cin >> n;

  vector<pair<int, int>> v (n);

  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v[i] = { a, b };
  }

  sort(v.begin(), v.end());

  ll time = 0, ret = 0;

  for (auto &[a, d] : v) {
    time += a;
    ret += (d - time);
  }

  cout << ret << "\n";
}
