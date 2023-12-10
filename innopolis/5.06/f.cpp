#include <iostream>
#include <vector>
#include <cmath>


typedef long long ll;
using namespace std;

bool f(ll x) {
    int cnt = 0;

    for (int i = 1; i < sqrt(x); ++i) {
        if (x % i == 0) {
            cnt += 2;

            if (i * i == x) {
                cnt--;
            }
        }
    }
    return cnt == 2;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m, sum = 0, k;

    cin >> n >> m;
    ll x = m;

    vector<ll> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (sum == m) {
            cout << "Yes" << endl;
            return 0;
        } else {
            k  = (m - sum) / a[i] + 1;
            if (a[i] > 1 && f(a[i]) && k > 1) {
                cout << "Yes " << i + 1 << " " << k << endl;
                return 0;
            }

        }

    }
    cout << "No" << endl;
    return 0;

}