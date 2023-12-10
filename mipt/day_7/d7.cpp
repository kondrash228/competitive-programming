#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Edge {
    ll u, v, w;
};

vector<Edge> g;
vector<ll> dsu;
vector<ll> sz;

ll find(ll v) {
    if (dsu[v] == v)
        return v;
    dsu[v] = find(dsu[v]);
    return dsu[v];
}

void unite(ll a, ll b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (sz[a] < sz[b]) {
        dsu[a] = b;
        sz[b] += sz[a];
    } else {
        dsu[b] = a;
        sz[a] += sz[b];
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m, a, b, w;
    cin >> n >> m;
    dsu.resize(n);
    sz.resize(n, 1);

    for (ll i = 0; i < n; ++i) {
        dsu[i] = i;
    }

    for (ll i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        a--, b--;
        g.push_back({a, b, w});
    }

    sort(g.begin(), g.end(), [](Edge a1, Edge a2) {return a1.w < a2.w;});

    ll cost = 0;

    for (auto [u, v, w] : g) {
        if (find(u) != find(v)) {
            unite(u, v);
            cost += w;
        }
    }
    cout << cost;

    return 0;
}