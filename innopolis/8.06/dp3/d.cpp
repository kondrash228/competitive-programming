#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int n, m;

    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cin >> m;
    vector<int> b(m);

    for (int i = 0; i < m; ++i)
        cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    dp[0][0] = 0;
    vector<vector<int>> p(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < m + 1; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    p[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }

    cout << dp[n][m];

}