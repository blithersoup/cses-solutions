#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define ll long long

int main() {
  ll n, a, ret = 0, mod;
  cin >> n;

  vector<ll> v (n + 1, 0), sums (n, 0);
  sums[0] = 1;

  for (int i = 1; i <= n; i++) {
    cin >> a;
    v[i] = a + v[i-1];
  }
  
  for (int i = 1; i <= n; i++) {
    mod = v[i] % n;
    if (mod < 0) mod += n;
    ret += sums[mod]++;
  }
  
  cout << ret << "\n";

}
