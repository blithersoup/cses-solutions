#include <iostream>
#include <stack>

using namespace std;

int main() {
  int n, x; cin >> n;
  bool p;
  
  stack<pair<int, int>> s;

  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (s.empty()) cout << 0 << " ";
    else {
      p = true;
      while (!s.empty() and p ) {
        p = false;
        if (s.top().first >= x) {
          s.pop();
          p = true;
        }

      }
      cout << ((s.empty()) ? 0 : s.top().second) << " ";
    }
    s.push({ x, i });
  }
}
