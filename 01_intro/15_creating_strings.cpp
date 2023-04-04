#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int factorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

vector<string> genstrings(string s) {
    int b = s.length() - 1;
    int z = factorial(s.length());
    int i, j;
    vector<string> ret{s};

    for (int w = 0; w < z; w++) {
        for (i = b; s[i - 1] >= s[i] and i > 1; i--) {}

        if (i-- == 0) return ret;

        for (j = b + 1; (j > i) and (s[j - 1] <= s[i]); j--) {}

        if (j-- == 0) return ret;

        iter_swap(s.begin() + i, s.begin() + j);

        if (i + 1 < b)
            reverse(s.begin() + i + 1, s.end());

        ret.push_back(s);
    }

    return ret;
}

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    vector<string> y = genstrings(s);

    vector<string>::iterator z = unique(y.begin(), y.end());

    cout << z - y.begin() << "\n";

    for (auto b = y.begin(); b != z; b++) {
        cout << *b << "\n";
    }

}
