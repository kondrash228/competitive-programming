#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, a, b;

    cin >> n >> m;
    vector<vector<int>> g(n);

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
    }

    vector<int> dist(n, -1);
    queue<int> q;

    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : g[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }

    }

    int mx = -1;

    for (int x : dist) {
        if (x > mx)
            mx = x;
    }

    cout << mx;
    return 0;
}