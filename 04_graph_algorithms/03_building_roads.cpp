#include "bits/stdc++.h"
using namespace std;

constexpr int N = 100001;

int root[N], Rank[N];

int find(int x) {
  if (x != root[x])
    root[x] = find(root[x]);
  return root[x];
}

void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (Rank[a] < Rank[b])
    swap(a, b);
  Rank[a] += Rank[b];
  root[b] = a;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    root[i] = i, Rank[i] = 1;


  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    unite(a, b);
  }
  
  unordered_set<int> s;
  
  for (int i = 1; i <= n; i++) {
    s.emplace(find(i));
  }
  
  cout << s.size() - 1 << "\n";
  unordered_set<int>::iterator it = s.begin();
  for (unsigned i = 1; i < s.size(); i++) {
    cout << *it << " " << *(++it) << "\n";
  }
}
