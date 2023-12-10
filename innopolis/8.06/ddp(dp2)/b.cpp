#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> dp(n, vector<ll>(m));
    vector<vector<char>> p(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }

    dp[0][0] = a[0][0];
    p[0][0] = '$';

    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + a[i][0];
        p[i][0] = 'D';
    }

    for (int i = 1; i < m; ++i) {
        dp[0][i] = dp[0][i - 1] + a[0][i];
        p[0][i] = 'R';
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i-1][j] + a[i][j];
                p[i][j] = 'D';
            } else {
                dp[i][j] = dp[i][j - 1] + a[i][j];
                p[i][j] = 'R';
            }
        }
    }

    cout << dp[n - 1][m - 1] << "\n";

    vector<char> path;
    int curI = n-1, curJ = m - 1;
    while (p[curI][curJ] != '$') {
        path.push_back(p[curI][curJ]);

        if (path.back()== 'D') curI--;
        else curJ--;
    }

    reverse(path.begin(), path.end());

    for (char c : path)
        cout << c;

    return 0;
}