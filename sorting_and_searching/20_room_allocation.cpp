#include <algorithm>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, a, b; cin >> n;

  // vector<int> rooms { 0 };
  multiset<pair<int, int>> rooms;
  decltype(rooms)::iterator it;
  
  vector<int> people (n + 1, 0);
  int s = 1;
  int p;

  vector<tuple<int, int, int>> input;
 
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    input.emplace_back(b, a, i);
  }

  sort(input.begin(), input.end()); 
  
  for (auto &[b, a, i] : input) {
    it = rooms.lower_bound({-a + 1, 0});
    if (it == rooms.end()) {
      people[i] = s;
      rooms.insert({-b, s++});
    }
    else {
      people[i] = it->second;
      p = it->second;
      rooms.erase(it);
      rooms.insert({-b, p});
    }

  }

  cout << rooms.size() << "\n";
  
  for (int i = 1; i <= n; i++) {
    cout << people[i] << " ";
  }

  cout << "\n";
}
