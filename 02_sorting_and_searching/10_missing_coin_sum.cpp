#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
int main() {
  ll n, x; cin >> n;

  vector<ll> v;

  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  
  sort(v.begin(), v.end());

  ll ret = 1;
  
  for (int i = 0; i < n and v[i] <= ret; i++) {
    ret += v[i];
  }

  cout << ret << "\n";
}
