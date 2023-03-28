#include <iostream>

using namespace std;


int main() {
  int n;
  cin >> n;

  long long ret = 0;

  for (int i = 5; i <= n; i *= 5) {
    ret += (n / i);
  }
  
  cout << ret << "\n";
}
