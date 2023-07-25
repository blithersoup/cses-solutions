#include "bits/stdc++.h"
using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
*/
// find_by_order(x)- x to i;  order_of_key(i)- i to x

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(), (x).end()
#define ll long long


void solve() {
  ll x1, y1, x2, y2, x3, y3;
  
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  ll p1 = ((x3 - x2) * (y3 - y1)) - ((y3 - y2) * (x3 - x1));


  if (p1 == 0) cout << "TOUCH\n";
  else if (p1 < 0) cout << "LEFT\n";
  else cout << "RIGHT\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int nc;
  cin >> nc;
  while (nc--) { solve(); }
}
