#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

const int INF = 1e9;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, a, b, w;
    cin >> n >> m;

    vector<pair<ll, ll>> graph[n];
    vector<ll> dist(n, INF);
    vector<bool> used(n);

    dist[0] = 0;
    set<pair<int, int>> q;
    q.insert({0, 0});

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        a--, b--;
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }


    while (!q.empty()) {
        auto [d, v] = *(q.begin());
        q.erase(q.begin());

        for (auto [u, w]: graph[v]) {
            if (dist[u] > dist[v] + w) {
                q.erase({dist[u], w});
                dist[u] = dist[v] + w;
                q.insert({dist[u], u});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << dist[i] << " ";
    }


}