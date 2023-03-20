#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define ll long long

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll n; cin >> n;
  vector<ll> v (n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  ll sum = accumulate(v.begin(), v.end(), 0LL);
  
  cout << max(sum, *(--v.end()) * 2) << "\n";
}
