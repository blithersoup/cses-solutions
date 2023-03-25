#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int n, k, a, b;
  cin >> n >> k;

  vector<pair<int, int>> v;
  multiset<int> movies;
  
  
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({ b, a });
  }

  sort(v.begin(), v.end());


  int ret = 0;


  multiset<int>::iterator it;

  for (int i = 0; i < k; i++) {
    movies.emplace(0);
  }

  for (auto &[end, start] : v) {
    it = movies.lower_bound(-start);
    if (it != movies.end()) {
      movies.erase(it);
      movies.emplace(-end);
      ret++;
    }
  }


  cout << ret << "\n";
}
