#include <iostream>
#include <vector>


using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(m, vector<int>(m));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u][v]++;
        if (graph[u][v] > 1) {
            cout << "YES" << "\n";
            return 0;
        } else {
            cout << "NO" << "\n";
            return 0;
        }
    }

}