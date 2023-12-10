#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;


int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> dp(n), a(n);
    vector<ll> p(n, -1);

    for (int i = 1; i < n; ++ i) {
        cin >> a[i];
    }

    for (int i = 1; i < n; ++i) {
        int idx = i - 1; // наиболее выгодная ступень

        for (int j = i - 2; j >= max(0, i - k); --j) {
            if (dp[j] > dp[idx])
                idx = j;
        }

        dp[i] = a[i] + dp[idx];
        p[i] = idx;
    }

    int cur = n - 1;
    vector<int> path;

    while (cur != -1) {
        path.push_back(cur + 1);
        cur = p[cur];
    }

    reverse(path.begin(), path.end());

    cout << dp[n-1] << "\n";
    cout << path.size() - 1 << "\n";

    for (int x : path)
        cout << x << " ";
}