#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct edge {
    ll u, v, w;
};

vector<edge> g;
vector<ll> p;
vector<ll> sz;

ll get(ll v) {
    if (p[v] == v) {
        return v;
    }
    return p[v] = get(p[v]);
}

void unite(ll u, ll v) {
    ll p1 = get(u);
    ll p2 = get(v);

    if (sz[p1] > sz[p2]) {
        p[p2] = p1;
        sz[p1] += sz[p2];
    } else {
        p[p1] = p2;
        sz[p2] += sz[p1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m, a, b, w;
    cin >> n >> m;
    p.resize(n);
    sz.resize(n, 1);

    for (ll i = 0; i < n; ++i) {
        p[i] = i;
    }

    for (ll i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        a--;
        b--;
        g.push_back({a, b, w});
    }
    sort(g.begin(), g.end(), [](edge a1, edge a2) { return a1.w < a2.w; });
    ll ans = 0;

    for (auto [u, v, w]: g) {
        if (get(u) != get(v)) {
            unite(u, v);
            ans += w;
        }
    }

    cout << ans;

    return 0;

}