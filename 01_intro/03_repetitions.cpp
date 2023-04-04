#include <iostream>
#include <string>

using namespace std;

int main() {
    string x;
    cin >> x;
    char c = 'B';
    int l = 0, maxL = 0;
    for (char a: x) {
        if (a == c) {
            l += 1;
        } else {
            maxL = max(l, maxL);
            l = 1;
            c = a;
        }
    }
    maxL = max(l, maxL);
    cout << maxL << "\n";
}
