#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    ll n, r;
    cin >> n >> r;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll sp = 0, cnt = 0;

    for (ll fp = 0; fp < n; ++fp) {
        while (sp != n && a[sp] - a[fp] <= r) {
            sp++;
        }
        cnt += n - sp;
    }
    cout << cnt ;

    return 0;
}