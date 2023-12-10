#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;

    cin >> n >> k;

    vector<int> a(k);

    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < k; ++i) {
        n-=a[i];
        if (n < 0) {
            cout << i << " ";
            return 0;
        }
    }

}