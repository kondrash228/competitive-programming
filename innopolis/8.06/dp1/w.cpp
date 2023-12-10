#include <iostream>
#include <vector>

using namespace std;
//2 -3 4 -5
// -2 3 -4 5

int main() {
    int n;
    cin >> n;

    vector<int> dp(n);
    vector<int> p(n, -1);
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    dp[1] = a[1];
    p[1] = 0;

    for (int i = 2; i < n; ++i) {
        if (dp[i-1] > dp[i-2]) {
            dp[i] = dp[i - 1] + a[i];
            p[i] = i - 1;
        }
        else {
            dp[i] = dp[i-2] + a[i];
            p[i] = i - 2;
        }
    }

    vector<int> path;
    int cur = n - 1;

    while (cur != -1) {
        path.push_back(cur + 1);
        cur = p[cur];
    }

    reverse(path.begin(), path.end());

    cout << dp[n-1] << "\n";

    for (int x : p)
        cout << x << " ";
}