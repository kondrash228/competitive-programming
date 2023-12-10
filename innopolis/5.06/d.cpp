#include <iostream>
#include <cmath>

using namespace std;
//typedef long long nn;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, cnt = 0;

    cin >> n;


    for (int i = 1; i <= int(sqrt(n)); ++i) {
        if (n % i == 0) {
            cnt += 2;

            if (i * i == n) {
                cnt--;
            }
        }
    }

    cout << cnt << endl;
}