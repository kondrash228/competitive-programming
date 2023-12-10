#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef double db;
const db EPS = 1e-7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto f = [](db x) {
        return x * x + 5 * x - 17;
    };

    db l = -1e4;
    db r = 1e4;

    while (abs(l - 1) > EPS) {
        db mid1 = l + (r - l) / 3;
        db mid2 = r - (r - l) / 3;

        if (f(mid1) < f(mid2)) {
            r = mid2;
        } else {
            l = mid1;
        }

    }

    cout << fixed << setprecision(15);
    cout << l;

}