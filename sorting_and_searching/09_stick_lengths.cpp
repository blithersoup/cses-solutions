#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
  ll n, p;
  cin >> n;

  vector<int> v;

  for (int i = 0; i < n; i++) {
    cin >> p;
    v.push_back(p);
  }

  sort(v.begin(), v.end());

  ll median = v[n / 2], ret = 0;

  for (int x : v) {
    ret += abs(x - median);
  }

  cout << ret << "\n";
  
}
