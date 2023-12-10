#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];


    vector<int> dp(n, 1);
    vector<int> p(n, -1);

    for (int i = 1; i < n; ++i) {
        int idx = -1;

        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j] && (idx == -1 || dp[idx] < dp[j]))
                idx = j;
            p[i] = idx;
            if (idx != -1)
                dp[i] = dp[idx] + 1;
        }
    }

    int last = 0;

    for (int i = 0; i < n; ++i) {
        if (dp[i] > dp[last])
            last = i;
    }

    cout << dp[last] << "\n";

    vector<int> path;

    while (last != -1) {
        path.push_back(a[last]);
        last = p[last];
    }

    reverse(path.begin(), path.end());

    for (int x: path)
        cout << x << " ";
}