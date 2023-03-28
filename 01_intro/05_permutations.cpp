#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << "\n";
    return 0;
  }
  if (n < 4) {
    cout << "NO SOLUTION\n";
  }
  
  int y = n / 4;
  int j = n % 4 + 4;
  int i, x;
  
  for (i = 1, x = 0; i < y; i++, x += 4) {
    cout << x + 2 << " " << x + 4 << " " << x + 1 << " " << x + 3 << " ";
  }
  if (j == 4) {
    cout << x + 2 << " " << x + 4 << " " << x + 1 << " " << x + 3 << " ";
  }
  if (j == 5) {
    cout << x + 1 << " " << x + 4 << " " << x + 2 << " " << x + 5 << " " << x + 3;
  }
  if (j == 6) {
    cout << x + 2 << " " << x + 4 << " " << x + 6 << " " << x + 1 << " " << x + 3 << " " << x + 5;
  }
  if (j == 7) {
    cout << x + 1 << " " << x + 3 << " " << x + 5 << " " << x + 7 << " " << x + 2 << " " << x + 4 << " " << x + 6;
  }
}
