#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n, k;


void bs(vector<int> &a, vector<int> &b, int x) {
    for (int i = 0; i < k; ++i) {
        ll l = 0;
        ll r = n;

        while (l + 1 < r) {

            ll mid = (l + r) / 2;

            if (a[mid] > x) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (a[l] == x) {
            cout << "YES " << a[l - 1] << "\n";
            break;
        } else if (b[l] == x) {
            cout << "YES " << b[l - 1] << "\n";
            break;
        } else {
            cout << "NO" << "\n";
            break;
        }
    }
}

int find_border(vector<int> &a) {
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            return i - 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    vector<int> a(n);

    vector<int> inc;
    vector<int> dec;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int border = find_border(a);


    for (int i = 0; i < border; ++i) {
        inc.push_back(a[i]);
    }

    for (int i = border; i < n; ++i) {
        dec.push_back(a[i]);
    }

    int x;

    sort(inc.begin(), inc.end());
    sort(dec.begin(), dec.end());

    for (int i = 0; i < k; ++i) {
        cin >> x;

        bs(inc, dec, x);
    }

}