#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define ll long long

int main() {
  ll n, a, b, x;

  cin >> n >> a >> b;

  vector<ll> pre (n + 1, 0);
  multiset<ll> vals;

  for (int i = 1; i <= n; i++) {
    cin >> x;

    pre[i] = pre[i - 1] + x;
  }

  ll ret = -2e18;
  
  for (int i = a; i <= n; i++) {
    if (i > b) vals.erase(vals.find(pre[i - b - 1]));
    vals.insert(pre[i - a]);
    ret = max(ret, pre[i] - *vals.begin());
  }

  cout << ret << "\n";
}
