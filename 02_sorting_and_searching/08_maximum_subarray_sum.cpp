#include <iostream>
#include <climits>

using namespace std;

#define ll long long

int main() {
  ll n, x;
  cin >> n;

  ll loc = -2e11, glob = -2e11;

  for (int i = 0; i < n; i++) {
    cin >> x;
    loc = max(x, loc + x);
    glob = max(loc, glob);
  }

  cout << glob << "\n";
}
