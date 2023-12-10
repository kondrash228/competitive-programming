#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;

    cin >> n;

    vector<ll> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];

    }
    ll cnt = 0;

    for (int j = 0; j < n; ++j) {
        for (int i = 2; i <= sqrt(a[j]); ++i){
            while (a[j] % i == 0) {
                if (i == 2)
                    cnt++;
                n /= i;
            }
        }
    }



    if (n != 1) {
        if (n==2)
            cnt++;
    }

    cout << cnt;

    return 0;

}

