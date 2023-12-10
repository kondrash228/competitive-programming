#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 1;
vector<int> color(MAXN);
vector<int> g[MAXN];
bool cycle = false;

void dfs(int v) {
    color[v] = 1;

    for (int u: g[v]) {
        if (!color[u])
            dfs(u);
        else if (color[u] == 1)
            cycle = true;
    }
    color[v] = 2;
}

int main() {
    int n, m, a, b, cnt = 0;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if (!color[i]) {
            dfs(i);
        }
    }
    cout << (cycle ? "YES" : "NO");

}