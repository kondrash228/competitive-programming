#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll w, h, n;
    cin >> w >> h >> n;

    ll l = 0;
    ll r = n * max(h, w);

    while (l + 1 < r) {
        ll mid = (l + r) / 2;

        if ((mid / h) * (mid / w) >= n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    if ((l / h) * (l / w) >= n) {
        cout << l;
    } else {
        cout << r;
    }
}