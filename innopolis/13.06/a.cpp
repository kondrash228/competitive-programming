#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s, f;
    cin >> n >> s >> f;


    vector<pair<int, int>> g[n];
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != -1 ) {
                g[i].push_back({j, a[i][j]});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ": ";
        for (auto [u, w]: g[i]) {
            cout << u << " " << w << " ";
        }
        cout << "\n";
    }

}