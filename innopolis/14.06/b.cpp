#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>


using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, num;
    char cmd;

    map<ll, ll> mp;

    cin >> n;
    mp[3] = 3;


    for (ll i = 0; i < n; ++i) {
        cin >> cmd;

        if (cmd == '+') {
            cin >> num;
            mp[num] = num;
        } else if (cmd == '-') {
            cin >> num;
            mp.erase(num);
        } else {
            cin >> num;
            if (mp.find(num) != mp.end()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }

}