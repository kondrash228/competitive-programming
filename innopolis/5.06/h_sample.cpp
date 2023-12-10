#include <iostream>
#include <map>
#include <numeric>

typedef long long ll;

using namespace std;

map<int, int> mapus;

void fille(int n) {
    mapus[1]++;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            mapus[i]++;
            mapus[n / i]++;
        }
    }
}





int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n;

    vector<pair<int, int>> a(n);
    vector<int> ans;

    for (int i = 0; i < n; i++)
        cin >> a[i].first, a[i].second = i;
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        if (mapus[a[i].first] == 1) ans.push_back(a[i].second);
        fille(a[i].first);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto i: ans) {
        cout << i + 1 << ' ';
    }
}