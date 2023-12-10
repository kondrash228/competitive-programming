#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MAX = 1e5 + 1;
vector<int> cnt(MAX);

void f(int n) {
    cnt[1]++;

    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            cnt[i]++;
            cnt[n / i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    vector<int> a2;

    for (int i = 0; i < n; ++i) {
        cin >> a[i].first, a[i].second = i;
    }

    sort(a.rbegin(), a.rend());


    for (int i = 0; i < n; ++i) {
        if (cnt[a[i].first] == 1)
            a2.push_back(a[i].second);

        f(a[i].first);
    }

    sort(a2.begin(), a2.end());

    cout << a2.size() << "\n";

    for (int i : a2) {
        cout << i + 1 << " ";
    }
    return 0;
}