#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  int n, x;
  cin >> n;

  unordered_set<int> y;

  for (int i = 0; i < n; i++) {
    cin >> x;
    y.emplace(x);
  }

  cout << y.size() << "\n";
}
