#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Node {
    ll mx{}, cnt{};
};

Node combine(Node a, Node b) {
    if (a.mx > b.mx) {
        return a;
    }
    if (a.mx < b.mx) {
        return b;
    }

    return {a.mx, a.cnt + b.cnt};
}

struct SegmentTree {
    ll size;
    vector<Node> tree;

    SegmentTree(vector<ll> &a) {
        size = a.size();
        tree.assign(4 * size, {});
        build(a, 0, 0, size);
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            tree[x] = {a[lx], 1};
            return;
        }

        ll mx = (rx + lx) / 2;

        build(a, 2 * x + 1, lx, mx);
        build(a, 2 * x + 2, mx, rx);

        tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
    }

    Node get(ll l, ll r, ll x, ll lx, ll rx) {
        if (l <= lx && rx <= r) {
            return tree[x];
        } else if (r <= lx || rx <= l) {
            return {};
        }

        ll mx = (lx + rx) / 2;

        return combine(get(l, r, 2 * x + 1, lx, mx), get(l, r, 2 * x + 2, mx, rx));
    }

    Node get(ll l, ll r) {
        return get(l, r, 0, 0, size);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> a(n);

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SegmentTree st(a);

    ll k, l, r;
    cin >> k;

    for (ll i = 0; i < k; ++i) {
        cin >> l >> r;
        l--, r--;

        Node g = st.get(l, r+1);

        cout << g.mx << " " << g.cnt << "\n";

    }


    return 0;
}