#include <iostream>
using std::cin;
using std::cout;

int main() {
  long long x;
  cin >> x;
  cout << x << " ";
  while (x > 1) {
    if (x & 1) {
      x = (3 * x) + 1;
    }
    else {
      x = x / 2;
    }
    cout << x << " ";
  }
}
