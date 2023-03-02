#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, a, b;
  cin >> n;

  vector<int> enter, leave;
  int total = 0, ret = 0;

  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    
    enter.push_back(a);
    leave.push_back(b);
  }

  sort(enter.begin(), enter.end());
  sort(leave.begin(), leave.end());

  int i = 0, j = 0;

  while (i < n) {
    if (enter[i] < leave[j]) {
      i++;
      total++;
      ret = max(total, ret);
    }
    else {
      j++;
      total--;
    }
  }

  cout << ret << "\n";
}
