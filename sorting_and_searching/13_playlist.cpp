#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int n, x, ret = 0, start = 0; cin >> n;
  unordered_map<int, int> m;

  for (int i = 1; i <= n; i++) {
    cin >> x;

    if (m[x] != 0) {
      start = max(start, m[x]);
    }
    m[x] = i;
    ret = max(ret, i - start);
  }
  cout << ret << "\n";
}
