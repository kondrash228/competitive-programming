#include <iostream>

using namespace std;
typedef long long ll;


ll b(ll x, ll n, ll p) {
    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0) {
        ll b2 = b(x, n/2, p);
        return b2 * b2 % p;
    } else {
        return x * b(x, n-1, p) % p;
    }

}
ll b_pow(ll x, ll n, ll p) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return x * b_pow(x, n - 1, p) % p;
    else
        ll b = b_pow(x, n / 2, p);

        return b * b % p;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll x, n, p;

    cin >> x >> n >> p;

    cout << b_pow(x,n,p) << endl;
}