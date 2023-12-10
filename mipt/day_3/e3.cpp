#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll combine_min(ll a, ll b) {
    if (a > b)
        return a;
    return b;
}

ll combine_max(ll a, ll b) {
    if (a < b)
        return a;
    return b;
}

struct SegmentTreeMax {
    ll size;
    vector<ll> tree;

    SegmentTreeMax(vector<ll> &a) {
        size = a.size();
        tree.assign(4 * size, 0);
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            tree[x] = a[lx];
            return;
        }

        ll mx = (rx + lx) / 2;

        build(a, 2 * x + 1, lx, mx);
        build(a, 2 * x + 2, mx, rx);

        tree[x] = combine_max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    ll get(ll l, ll r, ll x, ll lx, ll rx) {
        if (l <= lx && rx <= r) {
            return tree[x];
        } else if (r <= lx || rx <= l) {
            return 0;
        }

        ll mx = (rx + lx) / 2;

        return combine_max(get(l, r, 2 * x + 1, lx, mx), get(l, r, 2 * x + 2, mx, rx));
    }



    ll get_max(ll l, ll r) {
        return get(l, r, 0, 0, size);
    }
};

struct SegmentTreeMin {
    ll size;
    vector<ll> tree;

    SegmentTreeMin(vector<ll> &a) {
        size = a.size();
        tree.assign(4 * size, 0);
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            tree[x] = a[lx];
            return;
        }
        ll mx = (rx + lx) / 2;

        build(a, 2 * x + 1, lx, mx);
        build(a, 2 * x + 2, mx, rx);

        tree[x] = combine_min(tree[2 * x + 1], tree[2 * x + 2]);
    }

    ll get(ll l, ll r, ll x, ll lx, ll rx) {
        if (l <= rx && rx <= r) {
            return tree[x];
        } else if (r <= lx || rx <= l) {
            return 0;
        }

        ll mx = (rx + lx) / 2;

        return combine_min(get(l, r, 2 * x + 1, lx, mx), get(l, r, 2 * x + 2, mx, rx));
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;

    vector<int> el(n);

    for (int i = 1; i <= n; i++)
        el[i - 1] = (i * 1ll * i) % (12345) + ((i * 1ll * i) % (23456) * 1ll * i) % (23456);

    return 0;
}