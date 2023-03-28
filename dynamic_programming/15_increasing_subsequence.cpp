#include <vector>
#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;

  vector<int> v (n); for (int i = 0; i < n; i++) cin >> v[i];

  vector<int> dp;
  vector<int>::iterator it;
  
  
  for (int x : v) {
    if (!dp.size() or dp[dp.size() - 1] < x) {
      dp.push_back(x);
    }
    else {
      it = lower_bound(dp.begin(), dp.end(), x);
      *it = x;
    }
  }
  cout << dp.size() << "\n";
}
