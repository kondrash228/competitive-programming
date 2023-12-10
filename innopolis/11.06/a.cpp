#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;


    vector<vector<int>> graph(n, vector<int>(n));
    int r = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == 1)
                r++;
        }
    }
    cout << r/2 << "\n";
}