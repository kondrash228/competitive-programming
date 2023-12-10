#include <iostream>
#include <vector>
#include <string>
#include <cmath>

typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, sum = 0;
    cin >> n;
    vector<ll> a(n);

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (ll i = 0; i < n; ++i) {
        sum += a[i];
    }

    ll s2 = 0;

    for (int i = 0;i < n; ++i) {
        ll s = to_string(a[i]).size();

//        cout << "10 power by " << pow(10,s) * a[i] << endl;
        s2 += pow(10,s);

    }

    cout << (s2 + n) * sum ;


    return 0;

}