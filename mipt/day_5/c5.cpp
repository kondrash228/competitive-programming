#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s, f, a;
    cin >> n >> s >> f;
    s--, f--;

    vector<vector<pair<int, int>>> g(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a;
            if (i == j) continue;
            if (a != -1) {
                g[i].emplace_back(j, a);
            }
        }
    }

    vector<int> d(n, 1e9);
    set<pair<int, int>> q;

    d[s] = 0;
    q.insert({0, s});

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto [u, w]: g[v]) {
            if (d[u] > d[v] + w) {
                q.erase({d[u], u});
                d[u] = d[v] + w;
                q.insert({d[u], u});
            }
        }
    }
    if (d[f] != 1e9)
        cout << d[f] << "\n";
    else
        cout << -1 << "\n";

    return 0;
}