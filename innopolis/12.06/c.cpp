#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 100001;

vector<int> g[maxn];
vector<int> color(maxn);
vector<int> order;
bool cycle = false;

void dfs(int v) {
    color[v] = 1;
    for (int u: g[v]) {
        if (!color[u]) {
            dfs(u);
        } else if (color[u] == color[v]) {
            cycle = true;
        }
    }
    color[v] = 2;
    order.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, a, b;

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }

    for (int i = 0; i < n; ++i) {
        if (!color[i]) {
            dfs(i);
        }
    }

//    reverse(order.begin(), order.end());

    if (!cycle) {
        for (int x: order) {
            cout << x << " ";
        }
    } else {
        cout << -1;
    }
}