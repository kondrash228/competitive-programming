#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    vector<ll> fact;

    for (ll i = 2; i <= n; ++i) {
        while (n % i == 0 ) {
            fact.push_back(i);
            n /= i;
        }
    }

    if (n != 1) {
        fact.push_back(n);
    }


    if (fact.size() == 2 && fact[0] != fact[1]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;

}
