#include <iostream>
#include <vector>

using namespace std;

long long solve() {
  long long x, y;
  cin >> x >> y;

  if (max(x, y) == x) {
    long long base = (x - 1) * (x - 1);
    if (x % 2 == 1) {
      return base + y;
    }
    else {
      return (x * x) - y + 1;
    } 
  }
  else {
    long long base = (y - 1) * (y - 1);
    if (y % 2 == 0) { 
      return base + x;
    }
    else {
      return (y * y) - x + 1;
    }
  }
}



int main() {
  int n;
  cin >> n;
  while (n--) {
   cout << solve() << "\n";
  }
}
