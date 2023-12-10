#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, x, k;

    cin >> n >> k;

    vector<ll> a(n);

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (ll i = 0; i < k; ++i) {
        cin >> x;
        ll l = 0;
        ll r = n;

        while (l + 1 < r) {
            ll mid = (l + r) / 2;
            if (a[mid] > x) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << (abs(a[r] - x) < abs(a[l] - x) ? a[r] : a[l]) << "\n";
    }

}