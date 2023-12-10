#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 50001;

vector<int> g[maxn];
vector<bool> used(maxn);
vector<int> t;
bool cycle = false;

void dfs(int v, int p = -1) {
    used[v] = true;

    for (int u: g[v]) {
        if (!used[u]) {
            dfs(u, v);
        } else if (u != v) {
            cycle = false;
        }
    }
    t.push_back(v);
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
        if (!used[i]) {
            dfs(i);
        }
    }

    reverse(t.begin(), t.end());


    if (!cycle) {
        for (int x: t) {
            cout << x + 1 << " ";
        }
    } else {
        cout << -1;
    }

}