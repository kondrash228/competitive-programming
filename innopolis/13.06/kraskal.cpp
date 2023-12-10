#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct Edge {
    ll u, v, w;
};
vector<ll> p;
vector<ll> sz;

ll get_parent(ll v) {
    if (p[v] == v)
        return v;
    return p[v] = get_parent(p[v]);
}

void merge(ll a, ll b) {
    a = get_parent(a);
    b = get_parent(b);
    if (sz[a] > sz[b]) {
        swap(a, b);
    }

    sz[b] += sz[a];
    p[a] = b;
}

bool in_same_comp(ll a, ll b) {
    return p[a] == p[b];
}

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

ll Kraskal(vector<Edge> &v) {
    ll sum = 0;
    sort(v.begin(), v.end(), cmp);
    ll n = v.size();
    for (ll i = 0; i < n; i++) {
        if (!in_same_comp(v[i].u, v[i].v)) {
            merge(v[i].u, v[i].v);
            sum += v[i].w;
        }
    }
    return sum;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    p.resize(n);
    for (ll i = 0; i < n; i++) {
        p[i] = i;
    }
    vector<Edge> edges(n);
    sz.assign(n, 0);
    for (ll i = 0; i < n; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {u, v, w};
    }
    cout << Kraskal(edges) << "\n";
    return 0;
}

/*
7
1 2 3
2 3 5
3 5 6
2 5 4
3 4 2
4 5 7
1 5 1
*/