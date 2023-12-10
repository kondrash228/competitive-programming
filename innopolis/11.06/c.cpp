#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, v;

    cin >> n;

    vector<vector<int>> g(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> v, v--;
            g[i][v] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << g[i][j] << " ";

        }
        cout << "\n";
    }
}