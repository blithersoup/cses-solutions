#include <iostream>
using namespace std;

void solve() {
  float a, b;
  cin >> a >> b;
  if ((a < (b / 2)) or (b < (a / 2))) {
    cout << "AAA\n";
    cout << "NO\n";
    return;
  }
  int x = a, y = b;

  x %= 3;
  y %= 3;

  if ((x == 0) and (y == 0)) {
    cout << "AAb\n";
    cout << "YES\n";
    return;
  }
  else if ((min(x, y) == 1) and (max(x, y) == 2)) {
    cout << "AAw\n";
    cout << "YES\n";
    return;
  }
  else {
    cout << x << " " << y << "yo?\n";
    cout << "NO\n";
    return;
  }




}

int main() {
  int n; cin >> n;
  while (n--) { solve(); }
}
