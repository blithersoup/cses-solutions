#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, n, p; cin >> x >> n;

  multiset<int> distances { x };
  set<int> poles { 0, x };
  set<int>::iterator high, low;
  int _high, _low;

  for (int i = 0; i < n; i++) {
    cin >> p;

    low = poles.upper_bound(p);
    high = low--;
    _high = *high;
    _low = *low;
    
    poles.emplace(p);

  
    distances.erase(distances.find(_high - _low));
    distances.emplace(_high - p);
    distances.emplace(p - _low);
  

    cout << *(--distances.end()) << " ";



  }
}
