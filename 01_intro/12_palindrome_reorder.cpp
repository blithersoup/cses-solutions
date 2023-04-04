#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, int> m;

    for (char c: s) {
        m[c]++;
    }

    char odd;
    bool o = false;

    int p;
    for (int i = 0; i < 26; i++) {
        p = m[i + 'A'];
        if (p) {
            if (p & 1) {
                if (!o) {
                    odd = i + 'A';
                    o = true;
                } else {
                    cout << "NO SOLUTION\n";
                    return 0;
                }
            }
        }
    }

    for (auto x = m.begin(); x != m.end(); x++) {
        if (!o || x->first != odd) {
            for (int i = 0; i < x->second; i += 2) {
                cout << x->first;
            }
        }
    }

    if (o) {
        for (int i = 0; i < m[odd]; i++) {
            cout << odd;
        }
    }


    for (auto x = m.rbegin(); x != m.rend(); x++) {
        if (!o || x->first != odd) {
            for (int i = 0; i < x->second; i += 2) {
                cout << x->first;
            }
        }
    }

}
