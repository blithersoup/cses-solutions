#include <iostream>
#include <array>
#include <tuple>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x, y; cin >> n;

  vector<tuple<int, int, int>> pairs (n);
  ordered_set<pair<int, int>> opened, closed;
  vector<int> contains (n), within (n);

  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    pairs[i] = { x, y, i };
  }

  sort(pairs.begin(), pairs.end(), [](tuple<int, int, int> x, tuple<int, int, int> y) {
      return  ((get<0>(x) < get<0> (y)) or ((get<0>(x) == get<0>(y)) and get<1>(x) > get<1>(y)));
      });
  

  for (int i = 0, j = n - 1; i < n; i++, j--) {
    contains[get<2>(pairs[i])] = i - opened.order_of_key({get<1>(pairs[i]), -1});
    within[get<2>(pairs[j])] = closed.order_of_key({get<1>(pairs[j]) + 1, -1});

    opened.insert({get<1>(pairs[i]), i});
    closed.insert({get<1>(pairs[j]), i});
  }

  for (auto& y : within) cout << y << " ";
  cout << "\n";
  for (auto& y : contains) cout << y << " ";
  cout << "\n";
  
}
