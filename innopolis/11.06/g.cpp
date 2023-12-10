#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n,s;

    cin >> n >> s;
    s--;

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    vector<int> dist(n,-1);

    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u = 0; u < n; ++u) {
            if (graph[v][u] && dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    for (int x : dist)
        cout << x << " ";
}

