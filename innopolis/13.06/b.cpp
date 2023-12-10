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

    vector<vector<int>> graph(n, vector<int>(n));
    vector<pair<int, int>> g[n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] != -1) {
                g[i].push_back({j, graph[i][j]});
            }
        }
        cout << "\n";
    }

}