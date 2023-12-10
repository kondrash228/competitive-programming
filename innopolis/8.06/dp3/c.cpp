#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {

    string a, b;

    cin >> a >> b;

    int n = static_cast<int>(a.size());
    int m = static_cast<int>(b.size());

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; ++i)
        dp[i][0] = i;

    for (int i = 1; i <= m; ++i)
        dp[0][i] = i;


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int cost = a[i - 1] != b[j - 1];

            dp[i][j] = min(dp[i - 1][j - 1] + cost, min(dp[i - 1][j], dp[i][j - 1]) + 1);
        }
    }
    cout << dp[n][m];

}