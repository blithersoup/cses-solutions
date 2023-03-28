#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, x, w;
  cin >> n >> x;

  vector<int> v;

  for (int i = 0; i < n; i++) {
    cin >> w;
    v.push_back(w);
  }

  sort(v.rbegin(), v.rend());


  int i = 0, j = v.size() - 1;

  while (i + 1 < j) {
    if (v[i] + v[j] <= x) {
      j--;
    }
    i++;

  }
  
  if (!(((i < j) and (v[i] + v[j] <= x)) or (i == j))) i++;

  cout << ++i << "\n";
}
