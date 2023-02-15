#include <iostream>

using namespace std;
#define ll long long

int main() {
  int n;
  cin >> n;

  cout << 0 << "\n";
  if (n == 1) return 0;

  cout << 6 << "\n";
  if (n == 2) return 0;

  ll res, less;

  for (ll i = 3; i <= n; i++) {
    less = i - 1;
    less *= (i - 2) * 4;

    res = i * i;
    res *= (res - 1);
    res /= 2;

    cout << (res - less) << "\n";

  }
}
