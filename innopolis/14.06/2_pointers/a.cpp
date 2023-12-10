#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (ll i = 0; i < m; ++i) {
        cin >> b[i];
    }

    ll i = 0, j = 0, ans = abs(a[0] - b[0]);

    while (i < n && j < m) {
        ans = min(ans, abs(a[i] - b[j]));

        if (a[i] > b[j]) {
            j++;
        } else {
            i++;
        }
    }
    cout << ans;
    return 0;
}