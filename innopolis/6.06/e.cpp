#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
    if (a == 0 || b == 0) {
        return a + b;
    }
    return gcd(max(a, b) % min(a,b), min(a,b));
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, k, a;

    cin >> n >> k >> a;

    vector<pair<ll,ll>> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second; // l >> u
    }
    vector<ll> arr2;

    for (int i = 0; i < n; ++i) {
        ll d = arr[i].first / arr[i].second;
        arr2.push_back(d);
    }

    // lcm(a,b) * a[i] / gcd(a,b)
    ll nok = lcm(arr2[0], arr2[1]);

    for (size_t i = 0; i < arr2.size(); ++i) {
        nok = lcm(nok, arr2[i]);
    }

    if (a + nok <= k) {
        cout << "Yes\n";
        cout << a + nok;
    } else {
        cout << "No";
    }

}