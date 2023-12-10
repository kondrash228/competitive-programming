#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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

    vector<pair<ll, ll>> graph[n];

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        a--, b--;
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }

    vector<ll> dist(n, INF);
    vector<bool> used(n);

    dist[s] = 0;

    set<pair<ll, ll>> q;
    q.insert({0, s});


    while (!q.empty()) {
        auto [d, v] = *(q.begin());

        used[v] = true;
        for (auto [u, w]: graph[v]) {
            if (dist[u] > dist[v] + w) {
                q.erase({dist[u], u});
                dist[u] = dist[v] + w;
                q.insert({dist[u], u});
            }
        }
    }

}

