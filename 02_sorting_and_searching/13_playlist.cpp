#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define ll long long

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll n, x, ret = 0, start = 0; cin >> n;
  map<ll, ll> m;

  for (ll i = 1; i <= n; i++) {
    cin >> x;

    if (m[x] != 0) 
      start = max(start, m[x]);
    
    ret = max(ret, i - start);

    m[x] = i;
  }
  cout << ret << "\n";
}
