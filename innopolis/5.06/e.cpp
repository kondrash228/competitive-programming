#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;


ll cdels(ll x) {
    int cnt = 0;

    for (int i = 1; i <= int(sqrt(x)); ++i) {
        if (x % i == 0) {
            cnt += 2;

            if (i * i == x) {
                cnt--;
            }
        }
    }

    return cnt;
}

// 45360

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll x;

    cin >> x;

    for (int i = x; i <= x * 1.01; ++i) {
        cout << i << " " << cdels(i) << endl;
    }

    return 0;

}