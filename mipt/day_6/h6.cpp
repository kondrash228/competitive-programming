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

double operator*(V a, V b) {
    return a.x * b.x + a.y * b.y;
}

double operator^(V a, V b) {
    return a.x * b.y - a.y * b.x;
}

struct Line {
    double a{}, b{}, c{};
};

istream &operator>>(istream &in, Line &l) {
    return in >> l.a >> l.b >> l.c;
}

V intersect(Line l1, Line l2) {

    return {
            (l1.c * l2.b - l2.c * l1.b) / (l1.b * l2.a - l1.a * l2.b),
            (l2.c * l1.a - l1.c * l2.a) / (l1.b * l2.a - l1.a * l2.b)
    };
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Line l1, l2;
    cin >> l1 >> l2;

    V d = intersect(l1, l2);

    cout << fixed << setprecision(5) << d.x << " " << d.y;

    return 0;
}