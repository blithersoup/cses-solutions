#include <iostream>

using namespace std;

int main() {
  int n, x; cin >> n;

  int m [200001];

  for (int i = 1; i <= n; i++) {
    cin >> x;
    m[x] = i;
  }
  
  int ret = 1;

  for (int i = 2; i <= n; i++) {
    if (m[i - 1] > m[i]) ret++; 
  }

  cout << ret << "\n";
  

}
