#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
int main() {
    int n, k, l, f;

    cin >> n >> k >> l;

    vector<ll> dp(n);

    for (int i = 0; i < l; ++i)
        cin >> f, f--, dp[f] = -1;

    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
        if (dp[i] != -1) {
            for (int j = i - 1; j >= max(0, i - k); j--) {
                dp[i] += max(0ll,dp[j]);
            }
        }
    }

    cout << dp[n-1];
}