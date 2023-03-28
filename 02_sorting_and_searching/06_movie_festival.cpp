#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, a, b;
  cin >> n;

  vector<pair<int, int>> v;
  
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({ b, a });
  }
  
  sort(v.begin(), v.end());

  int i = 0, ret = 0, j = 0;


  while (i < n) {
    ret++;
    j++;
    while ((v[j].second < v[i].first) and (j < n)) {
      j++;
    }
    i = j;
  }
  cout << ret << "\n";
}
