#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct V {
    int x{}, y{};
};

istream &operator>>(istream &in, V &p) {
    return in >> p.x >> p.y;
}

V operator+(V a, V b) {
    return {a.x + b.x, a.y + b.y};
}

struct Line {
    int a{}, b{}, c{};
};

Line create_line(V p, V q) {
    int a = p.y - q.y;
    int b = q.x - p.x;
    int c = -a * p.x - b * p.y;
    return {a, b, c};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    V a, b;
    cin >> a >> b;
    V c = {-b.y, b.x};
    V d = a + c;
    cout << d.y - a.y << " " << a.x - d.x << " " << -(d.y - a.y) * a.x - (a.x - d.x) * a.y;

    return 0;
}