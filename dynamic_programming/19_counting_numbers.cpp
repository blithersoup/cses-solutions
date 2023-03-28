#include "bits/stdc++.h"
using namespace std;
#define ll long long

ll ans(ll in, vector<ll> &e9) {
  if (in == -1) return 0;
  vector<ll> digits;
  for (ll i = in; i > 0; i /= 10) digits.push_back(i % 10);

  ll ret = 0LL;

  for (int i = 0; i < (((int)digits.size()) - 1); i++) {
    ret += e9[i];
  }
  
  digits.push_back(10);
  
  for (int i = digits.size() - 2; i >= 0; i--) {
    ret += digits[i] * e9[i];
    if (digits[i] > digits[i + 1]) ret -= e9[i];
    if (digits[i] == digits[i + 1]) return ret;
  }
  return ret + 1;
}

int main() {
  vector<ll> e9 (19, 0);
  e9[0] = 1; 
  
  for (int i = 1; i <= 18; i++) {
    e9[i] = e9[i - 1] * 9;
  }
  
  ll a, b; cin >> a >> b;

  cout << ans(b, e9) - ans(a - 1, e9) << "\n";
}
