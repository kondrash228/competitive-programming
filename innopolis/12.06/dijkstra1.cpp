#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, a, b, w, s;
    cin >> n >> m >> s;
    s--;

    vector<pair<int, ll>> graph[n];

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        a--, b--;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    vector<ll> dist(n, INF);
    vector<bool> used(n);

    dist[s] = 0;

    for (int i = 0; i < n; ++i) {
        int v = -1;

        for (int j = 0; j < n; ++j) {
            if (!used[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }
        if (v == -1)
            break;

        used[v] = true;
        for (auto [u, w]: graph[v]) {
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
            }
        }
    }

}