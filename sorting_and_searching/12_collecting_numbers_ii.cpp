#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, x; cin >> n >> m;

  vector<int> v (n + 1, 0), mp (n + 2, 0);
  mp[n + 1] = n + 1;

  for (int i = 1; i <= n; i++) {
    cin >> x;
    v[i] = x; 
    mp[x] = i;
  }
  
  int ret = 1;

  for (int i = 2; i <= n; i++) {
    if (mp[i - 1] > mp[i]) ret++; 
  }
  

  int a, b, _a, _b, w, f;
  int al, au, bl, bu; // predecessor and successor of a and b
  
  for (int i = 0; i < m; i++) {
    cin >> w >> f;
    if (w != f) {
      _a = min(w, f);
      _b = max(w, f);
      
      a = v[_a];
      b = v[_b];
      
      al = mp[a - 1];
      au = mp[a + 1];
      bl = mp[b - 1];
      bu = mp[b + 1];
      
      if (a == (b - 1)) ret++;
      if (b == (a - 1)) ret--;

      if ((_a < al) and (al < _b)) ret--;
      if ((_a < au) and (au < _b)) ret++;
      if ((_a < bl) and (bl < _b)) ret++;
      if ((_a < bu) and (bu < _b)) ret--;

      swap(mp[a], mp[b]);
      swap(v[_a], v[_b]);
    }

    cout << ret << "\n";
  }



  

}
