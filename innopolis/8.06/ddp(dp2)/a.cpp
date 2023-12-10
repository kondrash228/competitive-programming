#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> a(n, vector<ll> (m));

    for (int i = 0; i < n; ++i) {
        a[i][0] = 1;
        for (int j = 0; j < m; ++j)
            a[0][j] = 1;
    }


    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            a[i][j] = (a[i][j-1] + a[i-1][j]) % 1000007;
        }
    }

    cout << a[n - 1][m - 1] << "\n";
}