#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
vector<pair<int, int>> moves = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};
int n, m;

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(vector<string> &table, vector<vector<bool>> &used, int x, int y) {
    used[x][y] = true;

    for (auto [dx, dy]: moves) {
        if (check(x + dx, y + dy) && !used[x + dx][y + dy] && table[x + dx][y + dy] == 'O') {
            dfs(table, used, x + dx, y + dy);
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    vector<string> table(n);
    vector<vector<bool>> used(n, vector<bool>(n));


    for (int i = 0; i < n; ++i) {
        cin >> table[i];
    }

    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!used[i][j] && table[i][j] == 'O') {
                dfs(table, used, i, j);
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
}