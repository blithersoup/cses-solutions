#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll mod = 1000000007;
  
  ll n; cin >> n;
  vector<vector<ll>> v (n, vector<ll> (n, 0));

  string s; cin >> s;
  v[0][0] = (s[0] == '.');

  for (int j = 1; j < n; j++) {
     if (s[j] == '.') 
       v[0][j] += v[0][j - 1];
  }

  for (int i = 1; i < n; i++) {
    cin >> s;
    if (s[0] == '.') {
      v[i][0] += v[i - 1][0];
      v[i][0] %= mod;
    }

    for (int j = 1; j < n; j++) {
      if (s[j] == '.') {
        v[i][j] += v[i - 1][j];
        v[i][j] += v[i][j - 1];
        v[i][j] %= mod;
      }
    }  
  }

  cout << v[n - 1][n - 1] << "\n";


}
