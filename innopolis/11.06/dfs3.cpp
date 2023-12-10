#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 1;
vector<int> color(MAXN);
vector<int> g[MAXN];
bool biparite = false;

void dfs(int v, int c) {
    color[v] = c;

    for (int u : g[v]) {
        if (!color[u])
            dfs(u, 3 - c);
        else if (color[u] == color[v])
            biparite = false;
    }
}
