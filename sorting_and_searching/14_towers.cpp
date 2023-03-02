#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, x; cin >> n;
  vector<int> q;
  vector<int>::iterator it;

  for (int i = 0; i < n; i++) {
    cin >> x;
    if (!q.size()) {
      q.push_back(x);
    }
    else if (*(q.end() - 1) <= x) {
      q.push_back(x);
    }
    else {
      *upper_bound(q.begin(), q.end(), x) = x;
    }
  }

  // because inserts are greedy, array maintains sortedness!

  cout << q.size() << "\n";
}
