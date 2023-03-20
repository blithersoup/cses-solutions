#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, x, a;
  cin >> n >> x;

  if (x == 1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  vector<pair<int, int>> v;
  
  int i = 0, j = --n;

  for (int f = 1; f <= n + 1; f++) {
    cin >> a;
    v.push_back({ a, f });
  }


  sort(v.begin(), v.end());


  while (i < j) {
    if (v[i].first + v[j].first == x) {
      cout << v[j].second << " " << v[i].second << "\n";
      return 0;
    }
    if (v[i].first + v[j].first < x) i++;
    else j--;
  }

  cout << "IMPOSSIBLE\n";
}
