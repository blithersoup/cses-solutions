#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x; cin >> n >> x;

  vector<int> memo (x + 1, 0);
  memo[0] = 1;

  vector<pair<int, int>> books (n);

  for (int i = 0; i < n; i++) cin >> books[i].first;
  for (int i = 0; i < n; i++) cin >> books[i].second;

  for (auto &[price, pages] : books) {
    for (int i = x; i >= 0; i--) {
      if (i - price >= 0 and memo[i - price]) memo[i] = max(memo[i], memo[i - price] + pages);
    }
  }

  cout << *max_element(memo.begin(), memo.end()) - 1 << "\n";
}
