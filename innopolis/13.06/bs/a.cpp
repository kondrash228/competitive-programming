#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x, k;

    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < k; ++i) {
        cin >> x;
        int l = 0;
        int r = n;

        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (a[mid] > x) {
                r = mid;
            } else {
                l = mid;
            }
        }

        cout << (a[l] == x ? "YES" : "NO") << "\n";
    }

}