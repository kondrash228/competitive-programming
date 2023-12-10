#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Node {
    int sum{}, added{};
};

Node combine(Node a, Node b) {
    return {
            a.sum + b.sum, // sum
            0 // added
    };
}


struct SegmentTree {
    int size;
    vector<Node> tree;

    SegmentTree(vector<int> &a) {
        size = a.size();
        tree.assign(4 * size, Node{});
        build(a, 0, 0, size);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            // list
            tree[x] = {a[lx], 0};
            return;
        }

        int mx = (lx + rx) / 2;

        build(a, 2 * x + 1, lx, mx);
        build(a, 2 * x + 2, mx, rx);


        tree[x].sum = tree[2 * x + 1].sum + tree[2 * x + 2].sum + tree[x].added * (rx - lx);

    }

    void add(int l, int r, int v, int x, int lx, int rx) {
        if (l <= lx && rx <= r) {
            tree[x].added += v;
            tree[x].sum += v * (rx - lx);
            return;
        }

        if (l <= lx || rx <= r) {
            return;
        }
        int mx = (rx + lx) / 2;

        add(l, r, v, 2 * x + 1, lx, mx);
        add(l, r, v, 2 * x + 2, mx, rx);

        tree[x].sum = tree[2 * x + 1].sum + tree[2 * x + 2].sum + tree[x].added * (rx - lx);
    }

    int get(int l, int r, int x, int lx, int rx, int added = 0) {
        if (l <= lx && rx <= r) {
            return tree[x].sum + tree[x].added * (rx - lx);

        } else if (r <= lx || rx <= l) {
            return 0;
        }

        added += tree[x].added;

        int mx = (rx + lx) / 2;

        return get(l, r, 2 * x + 1, lx, mx, added) + get(l, r, 2 * x + 2, mx, rx, added);
    }

//    void set(int i, int v, int x, int lx, int rx) {
//        if (lx - rx == 1) {
//            tree[x] = v;
//            return;
//        }
//
//        int mx = (lx + rx) / 2;
//
//        if (i < mx) {
//            set(i, x, 2 * x + 1, lx, mx);
//        } else {
//            set(i, x, 2 * x + 2, mx, rx);
//        }
//
//        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
//    }

    int get(int l, int r) {
        return get(l, r, 0, 0, size);
    }

//    void set(int i, int v) {
//        set(i, v, 0, 0, size);
//    }

    void add(int l ,int r, int v) {
        add(l, r, v, 0, 0, size);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    SegmentTree st(a);
    st.add(1, 5, 3);
    cout << st.get(2,4) << "\n";
    return 0;
}