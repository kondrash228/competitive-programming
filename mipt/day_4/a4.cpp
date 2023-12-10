#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;


struct SegmentTree {
    ll size;
    vector<ll> tree;

    SegmentTree(vector<ll> &a) {
        size = a.size();
        tree.assign(4 * size, 0);
        build(a, 0, 0, size);
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            tree[x] = a[lx];
            return;
        }

        ll mx = (lx + rx) / 2;

        build(a, 2 * x + 1, lx, mx);
        build(a, 2 * x + 2, mx, rx);

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    ll get(ll l, ll r, ll x, ll lx, ll rx) {
        if (l <= lx && rx <= r) {
            return tree[x];
        }

        if (r <= lx || rx <= l) {
            return 0;
        }

        ll mx = (rx + lx) / 2;

        return get(l, r, 2 * x + 1, lx, mx) + get(l, r, 2 * x + 2, mx, rx);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if (lx - rx == 1) {
            tree[x] = v;
            return;
        }

        ll mx = (lx + rx) / 2;

        if (i < mx) {
            set(i, v, 2 * x + 1, lx, mx);
        } else {
            set(i, v, 2 * x + 2, mx, rx);
        }

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    ll get(ll l, ll r) {
        return get(l, r, 0, 0, size);
    }

    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
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
    vector<ll> arr(n);

    arr[0] = 0;

    for (ll i = 1; i < n; ++i) {
        if (a[i] != a[i - 1])
            arr[i] = 1;
        else
            arr[i] = 0;
    }

    ll q, l, r;
    cin >> q;

    SegmentTree st(arr);

    for (ll i = 0; i < q; ++i) {
        cin >> l >> r;
        l--;

        cout << st.get(l, r) << "\n";
    }

    return 0;
}