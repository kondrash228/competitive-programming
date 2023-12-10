#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int MAXN = 1e3+1;
vector<bool> used(MAXN);
vector<int> g[MAXN];

void dfs(int v) {
    used[v] = true;

    for (int u : g[v]) {
        if (!used[u])
            dfs(u);
    }
}

int main() {
    int n, m, a, b, cnt = 0;
    cin >> n >> m;

    for (int i = 0; i <m;++i) {
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;

}