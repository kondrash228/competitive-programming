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

V operator-(V a, V b) {
    return {a.x - b.x, a.y - b.y};
}

double operator*(V a, V b) {
    return a.x * b.x + a.y * b.y;
}

double operator^(V a, V b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    V a, b, c;
    cin >> c >> a >> b;

    V ab = a - b;
    V ba = b - a;
    V ac = a - c;
    V bc = b - c;

    double c1 = ab ^ ac;
    double c2 = ab * ac;
    double c3 = ba * bc;

    if (c1 == 0 && c2 >= 0 && c3 >= 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }



    return 0;
}