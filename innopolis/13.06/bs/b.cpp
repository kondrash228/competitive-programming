#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;


const double EPS = 1e-7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double C;
    cin >> C;

    auto f = [](double x) {
        return x * x + sqrt(x);
    };

    double l = 0;
    double r = 1e5;

    while (abs(r - l) > EPS) {
        double mid = (l + r) / 2;

        if (f(mid) > C) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(15);
    cout << l;

}