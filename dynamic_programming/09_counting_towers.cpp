#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll mod = 1000000007;


  int t; cin >> t;


  vector<int> v (t);
  for (int i = 0; i < t; i++) cin >> v[i];

  int m = *max_element(v.begin(), v.end());
  vector<pair<ll, ll>> pre (m + 1);
  pre[1] = {1, 1};

  for (int i = 2; i <= m; i++) {
    pre[i].first = pre[i - 1].second + (pre[i - 1].first * 4);
    pre[i].second = pre[i - 1].first + (pre[i - 1].second * 2);
    pre[i].first %= mod;
    pre[i].second %= mod;

  }

  for (int a : v) {
    cout << (pre[a].first + pre[a].second) % mod << "\n";
  }

}
