#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, x, z;
  cin >> n >> x;

  vector<pair<int, int>> v (n);

  for (int i = 0; i < n; i++) {
    cin >> z;
    v[i] = {z, i + 1};
  }

  if (x < 4) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  sort(v.begin(), v.end());

  int a, b, c, cur0 = v[0].first, cur1, cur2;
 

  for (int i = 0; (i < (n - 3)) and (v[i].first < (x - 2)); i++) {
    cur0 = v[i].first;
    for (a = i + 1; (a < (n - 2)) and ((cur0 + v[a].first) < (x - 1)); a++) {
      cur1 = v[a].first;
      cur2 = cur0 + cur1;
  
      b = a + 1;
      c = n - 1;

      while (b < c) {
        if ((cur2 + v[b].first + v[c].first) == x) {
          cout << v[i].second << " " << v[a].second << " " << v[b].second << " " << v[c].second << "\n";
          return 0;
        }
        else if ((cur2 + v[b].first + v[c].first) < x) b++;
        else c--;
      }
    }
  }

  cout << "IMPOSSIBLE\n";
}
