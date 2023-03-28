#include <numeric>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> v (n);
  for (int i = 0; i < n; i++) cin >> v[i];
  
  int sum = accumulate(v.begin(), v.end(), 0);

  vector<bool> memo (sum + 1, false);
  memo[0] = true;

  for (int coin : v) {
    for (int i = sum; i > 0; i--) {
      if (i - coin >= 0 and memo[i - coin])
        memo[i] = true;
    }
  }
  
  set<int> s;

  for (int i = 1; i <= sum; i++) {
    if (memo[i]) s.emplace(i);
  }

  cout << s.size() << "\n";
  for (int x : s) cout << x << " ";
  cout << "\n";

}
