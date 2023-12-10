#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

bool is_valid(int x, int y, int n, int m, vector<vector<int>> &visited) {
    if (x < 1 || x > n || y < 1 || y > m) return false;
    if (visited[x][y] == 1) return false;

    return true;

}

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
        g[b].push_back(a);
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector<vector<int>> dist(n, vector<int>(n));
    vector<vector<int>> visited(n, vector<int>(n));
    queue<pair<int, int>> q;

    q.push({x1, y1});
    dist[x1][y1] = 0;
    visited[x1][y1] = 1;

    while (!q.empty()) {
        int vx = q.front().first;
        int vy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            if (is_valid(vx, vy, n, m, visited)) {
                int nx =
            }
        }
    }


    return 0;
}