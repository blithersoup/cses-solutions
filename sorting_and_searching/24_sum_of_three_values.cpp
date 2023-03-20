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

  if (x < 3) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  sort(v.begin(), v.end());

  int a, b, cur = v[0].first;
  

  for (int i = 0; (i < n) and (cur < (x - 1)); i++, cur = v[i].first) {
    a = i + 1;
    b = n - 1;

    while (a < b) {
      if ((cur + v[a].first + v[b].first) == x) {
        cout << v[i].second << " " << v[a].second << " " << v[b].second << "\n";
        return 0;
      }
      else if ((cur + v[a].first + v[b].first) < x) a++;
      else b--;
    }
  }

  cout << "IMPOSSIBLE\n";
}
