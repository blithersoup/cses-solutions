#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int n, x, a;
  cin >> n >> x;

  unordered_map<int, int> m;

  for (int i = 1; i <= n; i++) {
    cin >> a;

    if (m.find(a)!= m.end()) {
      cout << i << " " << m[a] << "\n";
      return 0;
    }

    m[x - a] = i;

  }

  cout << "IMPOSSIBLE\n";
}
