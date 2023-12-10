#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,k;

    cin >> n >> k;

    vector<int> a(n);
    vector<int> b(n + 1);
    b[0]=0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];

    }

    for (int i = 1; i < n + 1;  ++i) {
        if (a[i-1]<0)
            continue;
        b[i] = b[i-1] + a[i-1];

    }



    int max = -1e6 - 1;

    for (int i = k; i <= n; ++i) {
        if (b[i] > max)
            max=b[i];
    }

    cout << max;

}