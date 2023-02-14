#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;


int main() {
  int n;
  cin >> n;
  vector<int> vi;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    vi.push_back(x);
  }

  vector<long long> j;
  deque<pair<int, long long>> y;

  y.push_back({0, 0});
  
  pair<int, long long> p;
  while (y[0].first != n) {
    p = y[0];
    y.pop_front();
    y.push_back({p.first + 1, vi[p.first] + p.second});
    y.push_back({p.first + 1, -vi[p.first] + p.second});
  }
  
  y.erase(remove_if(y.begin(), y.end(), [&](auto x) {return x.second < 0;}), y.end());

  sort(y.begin(), y.end(), [&](auto x, auto y) {return x.second < y.second;} );

  cout << y[0].second << "\n";
  
}
