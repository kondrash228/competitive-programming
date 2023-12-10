#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

int l(int n) {
    int cnt = 0;

    for (int i = 2; i <= sqrt(n); ++i) {
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
    }

    if (n != 1) {
        cnt++;
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    int len = l(n);

    vector<int> a(len);
    int j = 0;

    for (int i = 2; i <= sqrt(n); ++i) {
        while (n % i == 0) {
            a[j] = i;
            n /= i;
            j++;

        }

    }

    if (n != 1) {
        a[len - 1] = n;
    }

    if (a[0] != a[len - 1] && len == 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}