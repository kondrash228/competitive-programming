#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
int main() {
    int n, k;

    cin >> n >> k;

    vector<ll> dp(n);

    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= max(0, i - k); j--) {
            dp[i] += dp[j];
        }
    }

    ll sum = dp[0];

    for (int i = 1; i < n; ++i) {
        dp[i] = sum;
        sum += dp[i];
    }

    for (int i = k; i < n; ++i) {
        dp[i] = sum;
        sum += dp[i] - dp[i-k];
    }

    cout << dp[n-1];
}