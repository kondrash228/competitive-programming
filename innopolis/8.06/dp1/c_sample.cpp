#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
ll n,k, mp = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    vector<ll> a(n);

    ll ans = LONG_LONG_MIN;


    for (int i = 0 ; i < n; ++i) {
        cin >> a[i];
        if (i > 0)
            a[i] += a[i - 1];

        if (i >= k - 1) {
            ans = max(ans, a[i] - mp);
            mp = min(mp, a[i - k + 1]);
        }
    }
    cout << ans << "\n";

    return 0;
}