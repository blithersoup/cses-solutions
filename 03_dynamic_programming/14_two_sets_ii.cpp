#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main() {
  ll mod = 1000000007;
  ll n;
  cin >> n;

  ll sum = (n * (n + 1)) / 2;

  if (sum % 2 != 0) {
    cout << "0\n";
    return 0;
  }

  vector<int> v(250000, 0);

  for (int i = 1; i < n; i++) {
    for (int j = (i * (i + 1)) / 2; j >= 1; j--) {
      if (v[j] > 0) {
        v[j + i] += v[j];
        v[j + i] %= mod;
      }
    }

    v[i]++;
  }
  cout << v[(n * (n + 1)) / 4] % mod << "\n";
}
