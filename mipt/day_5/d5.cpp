#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;

void dijkstra(int s, int  n) {
    vector<ll> dist(n, 1e9);
    priority_queue<pair<ll,ll> > q;

    dist[s] = 0;
    q.push({0, s});


    while (!q.empty()) {
        ll v = q.top().second;
        q.pop();
        if (visited[v]) continue;
        visited[v] = true;

        for (auto [u, w] : g[v]) {
            if (dist[u] > dist[v] + w)  {
                dist[u] = dist[v] + w;
                q.push({-dist[u], u});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, s, f, a, b, w;
    cin >> n >> m >> s >> f;
    --s; --f;
    vector<vector<pair<ll, ll>>> g(n);
    bool visited[n];
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        g[--a].emplace_back(--b, w);
        g[b].emplace_back(a, w);
    }

    vector<ll> dist(n, 1e9);
    priority_queue<pair<ll,ll> > q;

    dist[s] = 0;
    q.push({0, s});


    while (!q.empty()) {
        ll v = q.top().second;
        q.pop();
        if (visited[v]) continue;
        visited[v] = true;

        for (auto [u, w] : g[v]) {
            if (dist[u] > dist[v] + w)  {
                dist[u] = dist[v] + w;
                q.push({-dist[u], u});
            }
        }
    }
    if (dist[f] != 1e9)
        cout  << dist[f];
    else
        cout << -1;

    return 0;
}