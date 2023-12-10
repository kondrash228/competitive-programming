#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    int ans = 0;
    cin >> n >> k;

    vector<ll> mx(n), a(n);


    cin >> a[0], mx[0] = a[0];

    for (int i = 0; i < n;++i){
        cin >> a[i];
        mx[i] = max(mx[i-1], a[i]);
    }

    for (int i = k; i < n; ++i) {
        ans = max(ans, a[i] *mx[i-k]);
    }

    cout << ans << "\n";


    return 0;
}

