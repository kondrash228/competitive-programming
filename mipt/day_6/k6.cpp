#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>


using namespace std;
typedef long double ld;
typedef long long ll;

struct V {
    ld x{}, y{};
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

double len2(V a) {
    return a * a;
}

double len(V a) {
    return sqrt(len2(a));
}

double dist2(V a, V b) {
    return len2(a - b);
}

double dist(V a, V b) {
    return sqrt(dist2(a, b));
}

struct Line {
    ld a{}, b{}, c{};
};

double dist(V p, Line l) {
    return abs((l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b));
}

Line create_line(V p, V q) {
    ld a = p.y - q.y;
    ld b = q.x - p.x;
    ld c = -a * p.x - b * p.y;
    return {a, b, c};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    V a, b, c;

    cin >> c >> a >> b;

    if ((b - a) * (c - a) >= 0)
        cout << fixed << setprecision(5) << dist(a, create_line(a, b));
    else
        cout << abs(dist(a, c));


    return 0;
}