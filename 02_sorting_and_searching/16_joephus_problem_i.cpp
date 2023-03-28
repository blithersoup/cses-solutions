#include <iostream>
#include <set>

using namespace std;

int main() {
  int n; cin >> n;
  set<int> s;
  set<int>::iterator it;

  for (int i = 1; i <= n; i++) {
    s.emplace(i);
  }

  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  
  it = s.begin();
  it++;
  cout << *it << " ";
  s.erase(it++);

  while (s.size()) {
    if (it == s.end()) it = s.begin();
    it++;
    if (it == s.end()) it = s.begin();
    cout << *it << " ";
    s.erase(it++);
  }
}
