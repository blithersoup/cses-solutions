#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int two_queens(int row, int queens[8], int diag1, int diag2, vector<vector<bool>> &blocked) {

  if (row == 8) {
    return 1;
  }

  int sum = 0;

  for (int i = 0; i < 8; i++) {

    if (find(queens, queens + row, i) == queens + row) {

      if (!(diag1 & (1 << (row + i)))) {

        if (!(diag2 & (1 << (row - i + 8)))) {

          if (!blocked[row][i]) {

            queens[row] = i;
            sum += two_queens(row + 1, queens, diag1 | (1 << (row + i)), diag2 | (1 << (row - i + 8)), blocked);

          }
        }
      }
    }
  }
  return sum;
}

int main() {

  string s;
  vector<vector<bool>> blocked (8, vector<bool> (8, false));

  for (int i = 0; i < 8; i++) {
    cin >> s;
    for (int j = 0; j < 8; j++) {
      if (s[j] == '*') {
        blocked[i][j] = true;
      }
    }
  }

  int queens[8];
  for (int i = 0; i < 8; i++) {
    queens[i] = -1;
  }
  
  int diag1 = 0, diag2 = 0;

  cout << two_queens(0, queens, diag1, diag2, blocked) << "\n";

}
