#include <iostream>
#include <vector>

using namespace std;
const int maxn = 1e3 + 1;
vector<bool> used(maxn);
vector<int> g[maxn];

void dfs(int v) {
    used[v] = true;
    for (int u: g[v]) {
        if (!used[u])
            dfs(u);
    }
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
        g[b].push_back(a);
    }



    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cnt++;
            dfs(i);
        }
    }

    cout << cnt;
}