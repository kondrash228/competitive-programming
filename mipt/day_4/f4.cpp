#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Node {
    ll sum{}, added{};
};


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
            tree[x] = {a[lx], 0};
            return;
        }

        ll mx = (rx + lx) / 2;

        build(a, 2 * x + 1, lx, mx);
        build(a, 2 * x + 2, mx, rx);

        tree[x].sum = tree[2 * x + 1].sum + tree[2 * x + 2].sum + tree[x].added * (rx - lx);
    }

    void add(ll l, ll r, ll v, ll x, ll lx, ll rx) {
        if (l <= lx && rx <= r) {
            tree[x].added += v;
            tree[x].sum += v * (rx - lx);
            return;
        } else if (r <= lx || rx <= l) {
            return;
        }

        ll mx = (rx + lx) / 2;

        add(l, r, v, 2 * x + 1, lx, mx);
        add(l, r, v, 2 * x + 2, mx, rx);

        tree[x].sum = tree[2 * x + 1].sum + tree[2 * x + 2].sum + tree[x].added * (rx - lx);

    }

    ll get(ll l, ll r, ll x, ll lx, ll rx, ll added = 0) {
        if (l <= lx && rx <= r) {
            return tree[x].sum + tree[x].added * (rx - lx);
        } else if (r <= lx || rx <= l) {
            return {};
        }

        added += tree[x].added;
        ll mx = (rx + lx) / 2;

        return get(l, r, 2 * x + 1, l, mx, added) + get(l, r, 2 * x + 2, mx, rx, added);
    }

    ll get(ll l, ll r) {
        return get(l, r, 0, 0, size);
    }

    void add(ll l, ll r, ll v) {
        add(l, r, v, 0, 0, size);
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<ll> a = {1, 2, 3, 4, 5, 6, 7};
    SegmentTree st(a);

    st.add(1, 5, 3);
    cout << st.get(2,4) << "\n";

    return 0;
}