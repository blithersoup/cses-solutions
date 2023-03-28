#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
  int n, k, x, distinct = 0;
  cin >> n >> k;

  vector<int> v;

  unordered_map<int, int> m;

  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }

  long long j = 0;
  long long ret = 0;
  bool p;

  for (long long i = 0; i < n; i++) {
    p = true;
    while ((j < n) and p) {
      if ((!m[v[j]]) and (distinct == k)) p = false;
      else {
        if (!m[v[j]]) {
        distinct++;
        }
        m[v[j]]++;
        j++;
      }
    }
    ret += (j - i);

    if (m[v[i]] == 1) {
      distinct--;
    }
    m[v[i]]--;
  }

  cout << ret << "\n";
}
