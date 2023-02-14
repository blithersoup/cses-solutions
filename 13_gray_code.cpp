#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

int main() {
  vector<int> v { 0, 1 };
  
  int n;
  cin >> n;
  
  int s = 2;
  
  for (int i = 1; i < n; i++) {
  
    for (int j = s - 1; j >= 0; j--) {
      v.push_back((v[j] << 1) | 1);
    }
    
    for (int j = 0; j < s; j++) {
      v[j] <<= 1;
    }
    
    s *= 2;
  }
  
  for (int i = 0; i < s; i++) {
    bitset<16> x (v[i]);
    cout << x.to_string().substr(16-n) << "\n";
  }

}
