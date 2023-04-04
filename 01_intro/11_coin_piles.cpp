#include <iostream>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    if ((a < ((b + 1) / 2)) or (b < ((a + 1) / 2))) {
        cout << "NO\n";
        return;
    }

    int x = a, y = b;

    x %= 3;
    y %= 3;

    if ((x == 0) and (y == 0)) {
        cout << "YES\n";
        return;
    } else if ((min(x, y) == 1) and (max(x, y) == 2)) {
        cout << "YES\n";
        return;
    } else {
        cout << "NO\n";
        return;
    }

}

int main() {
    int n;
    cin >> n;
    while (n--) { solve(); }
}
