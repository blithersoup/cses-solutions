#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    cout.precision(20);

    long long mod = 1e9 + 7;
    long long y = 2;
    for (int i = 1; i < x; i++) {
        y *= 2;
        y = y % mod;
    }
    cout << y << "\n";
}
