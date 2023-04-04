#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long total = 0;
    vector<int> x;
    int y;
    for (int i = 0; i < n; i++) {
        cin >> y;
        x.push_back(y);
    }
    for (int i = 1; i < n; i++) {
        if (x[i] < x[i - 1]) {
            total += (x[i - 1] - x[i]);
            x[i] = x[i - 1];
        }
    }
    cout << total << "\n";
}
