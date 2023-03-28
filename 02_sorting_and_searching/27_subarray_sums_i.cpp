#include <iostream>
#include <vector>
#include <unordered_set>
 
using namespace std;
 
#define ll long long
 
int main() {
  ll n, x, a;
  cin >> n >> x;
 
  vector<ll> v (n + 1, 0);
  unordered_set<ll> prefix_sums { 0 };
 
 
  for (int i = 1; i <= n; i++) {
    cin >> a;
    v[i] = a;
    v[i] += v[i - 1];
  }
 
  int ret = 0;
 
  for (int i = 1; i <= n; i++) {
    if (prefix_sums.find(v[i] - x) != prefix_sums.end()) ret++;
 
    prefix_sums.emplace(v[i]);
  }
 
  cout << ret << "\n";
}