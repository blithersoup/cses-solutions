#include <ios>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
 
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n, k, pos = 0;
  cin >> n >> k;
  indexed_set s;
  int it;
 
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
 
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
 
  if (k == 0) {
    for (auto x : s)
      cout << x << " ";
    cout << "\n";
    return 0;
  }
 
  while (n) {
    pos = (pos + k) % n;
    it = *s.find_by_order(pos);
    cout << it << " ";
    s.erase(it);
    n--;
  }
}
