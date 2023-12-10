#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct SegmentTree {
    int size;
    vector<int> tree;

    SegmentTree(vector<int> &a) {
        size = a.size();
        tree.assign(4 * size, 0);
        build(a, 0, 0, size);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = a[lx];
            return;
        }

        int mx = (lx + rx) / 2;

        build(a, 2 * x + 1, lx, mx);
        build(a, 2 * x + 2, mx, rx);

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    int get(int l, int r, int x, int lx, int rx) {
        if (l <= lx && rx <= r) {
            return tree[x];
        }

        if (r <= lx || rx <= l) {
            return 0;
        }

        int mx = (rx + lx) / 2;

        return get(l, r, 2 * x + 1, lx, mx) + get(l, r, 2 * x + 2, mx, rx);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (lx - rx == 1) {
            tree[x] = v;
            return;
        }

        int mx = (lx + rx) / 2;

        if (i < mx) {
            set(i, v, 2 * x + 1, lx, mx);
        } else {
            set(i, v, 2 * x + 2, mx, rx);
        }

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    int get(int l, int r) {
        return get(l, r, 0, 0, size);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int m, l, r, idx, v;
    string s;
    cin >> m;

    SegmentTree st(a);
    vector<int> ans;

    for (int i = 0; i < m; ++i) {
        cin >> s;

        if (s == "s") {
            cin >> l >> r;
            l--, r--;
            cout << st.get(l, r) << " ";
        }
        if (s == "u") {
            cin >> idx >> v;
            idx--;
            st.set(idx, v);
        }

    }

    return 0;
}