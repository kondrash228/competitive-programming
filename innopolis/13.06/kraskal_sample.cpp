#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// безопасное ребро

struct Edge {
    int v, u, w;
};

vector<Edge> graph;

struct DSU {
    vector<int> p;
    vector<int> sz;

    DSU(int n) {
        p.resize(n);
        sz.resize(n, 1);

        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }

    int root(int x) {
        if (p[x] == x) return x;
        return p[x] == root(p[x]);
    }

    void merger(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y)
            return;

        if (sz[x] > sz[y])
            swap(x, y);

        p[x] = y;
        sz[y] += sz[x];

    }

    bool connected(int x, int y) {
        return root(x) == root(y);
    }
};


bool cmp(Edge o1, Edge o2) {
    return o1.w < o2.w;
}

int min_spannig_tree(vector<Edge> &edges, int n) {
    sort(edges.begin(), edges.end(), cmp);

    int sum = 0;
    DSU dsu(n);

    for (auto [v, u, w]: edges) {
        if (!dsu.connected(v, u)) {
            dsu.merger(v, u);
            sum += w;
        }

    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


}
