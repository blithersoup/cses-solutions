#include <iostream>
#include <vector>

using namespace std;


void tower(int n, int from, int to, int with, vector<pair<int, int>> &pairs) {
    if (n == 0) return;
    tower(n - 1, from, with, to, pairs);
    pairs.push_back({from, to});
    tower(n - 1, with, to, from, pairs);
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> pairs;
    tower(n, 1, 3, 2, pairs);
    cout << pairs.size() << "\n";

    for (auto x: pairs) {
        cout << x.first << " " << x.second << "\n";
    }
}
