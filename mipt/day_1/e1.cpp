#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

const int maxn = 1e5 + 1;

vector<int> g[maxn];
vector<int> visited;
vector<int> ans;

bool cycle = false;

void dfs(int v) {
    visited[v] = 1;
    ans.push_back(v);

    for (int to: g[v]) {
        if (visited[to] == 0) {
            dfs(to);
        } else if (visited[to] == 1) {
            cycle = true;

            cout << "YES\n";
            bool c = false;

            for (int i = 0; i < ans.size(); ++i) {
                if (ans[i] == to) {
                    c = true;
                }
                if (c) {
                    cout << ans[i] << " ";
                }

            }
            exit(0);
        }
    }
    visited[v] = 2;
    ans.pop_back();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m, a, b;
    cin >> n >> m;

    visited.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }

    cout << "NO";

    return 0;
}