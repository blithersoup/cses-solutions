#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ll n; cin >> n;
  vector<ll> start (n), end(n), price(n);
  map<int, int> compress;
  for (int i = 0; i < n; i++) {
    cin >> start[i] >> end[i] >> price[i];
    compress[start[i]] = 0;
    compress[end[i]] = 0;
  }

  int num = 1;
  for (auto &p : compress) {
    p.second = num++;
  }

  vector<vector<pair<int, int>>> projects_after_date (num);
  for (int i = 0; i < n; i++) {
    projects_after_date[ compress[ end[i] ] ].push_back({ compress[start[i]], price[i] });
  }

  vector<ll> dp (num + 1, 0);

  for (int i = 1; i <= num; i++) {
    dp[i] = dp[i - 1];
    for (auto& p : projects_after_date[i - 1]) {
      dp[i] = max(dp[i], dp[p.first] + p.second);
    }
  }


  cout << dp[num] << "\n";

}
