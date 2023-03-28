#include <vector>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x; cin >> n;

  vector<int> v ( n + 1, 10000000 );
  v[n] = 0;

  for (int i = n; i > 0; i--) {
    for (int j = i; j > 0; j /= 10) {
      x = j % 10;
      if (i - x >= 0) {
        v[i - x] = min(v[i - x], v[i] + 1); 
      }
    }
  }

  cout << v[0] << "\n";

}
