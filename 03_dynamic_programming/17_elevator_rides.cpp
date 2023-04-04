#include "bits/stdc++.h"
using namespace std;

int main() {
  int n, x; cin >> n >> x;
  vector<int> v (n);
  for (auto& i : v) cin >> i;
  
  vector<pair<int, int>> states ((1 << n), {n + 1, x + 1});
  states[0] = {1, 0};

  for (int mask = 1; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        auto &[elevators, weight] = states[mask ^ (1 << i)];
        if (weight + v[i] > x) {
          states[mask] = min(states[mask], {elevators + 1, v[i]});
        }
        else {
          states[mask] = min(states[mask], {elevators, weight + v[i] });
        }
      }
    }
  }

  cout << states[(1 << n) - 1].first << "\n";
}
