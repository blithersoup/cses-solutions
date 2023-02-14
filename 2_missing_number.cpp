#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  long long x; cin >> x;
  long long p;
  long long y = 0;
  for (int i = 1; i < x; i++) {
    cin >> p;
    y += p;
  }
  cout << (((x * (x + 1)) / 2) - y) << "\n";
}
