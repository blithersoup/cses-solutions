#include <iostream>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;

    ll sum = (n * (n + 1)) / 2;

    if (sum % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    ll half = sum / 2, tot = 0, i;

    for (i = 1; tot < half; i++) {
        tot += i;
    }
    i--;

    ll diff = tot - half, num;

    if (diff) {

        cout << "YES\n" << i - 1 << "\n";

        for (num = 1; num <= i; num++) {
            if (num != diff)
                cout << num << " ";
        }

        cout << "\n" << n - i + 1 << "\n" << diff << " ";

        for (num = i + 1; num <= n; num++) {
            cout << num << " ";
        }

    } else {

        cout << "YES\n" << i << "\n";

        for (num = 1; num <= i; num++) {
            cout << num << " ";
        }

        cout << "\n" << n - i << "\n";

        for (num = i + 1; num <= n; num++) {
            cout << num << " ";
        }
    }

}
