#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;
typedef long long ll;

struct V {
    double x{}, y{};
};

istream &operator>>(istream &in, V &p) {
    return in >> p.x >> p.y;
}

V operator-(V a, V b) {
    return {a.x - b.x, a.y - b.y};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    V a, b, c;
    cin >> a >> b >> c;

    V bc = b - c;

    V l = a - bc;

    cout << fixed << setprecision(5) << l.y;

    return 0;
}