#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;

struct V {
    int x{}, y{};
};

istream &operator>>(istream &in, V &p) {
    return in >> p.x >> p.y;
}

ostream &operator<<(ostream &out, V p) {
    return out << p.x << " " << p.y;
}

double operator*(V a, V b) {
    return a.x * b.x + a.y * b.y;
}

double operator^(V a, V b) {
    return a.x * b.y - a.y * b.x;
}

struct Line {
    double a{}, b{}, c{};
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x0, y0, a, b, c;
    cin >> x0 >> y0 >> a >> b >> c;

    double d = abs((a * x0 + b * y0 + c) / sqrt(a * a + b * b));
    cout << fixed << setprecision(5) << d;

    return 0;
}