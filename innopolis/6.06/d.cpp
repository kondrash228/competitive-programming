#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (a == 0 || b == 0)
        return a + b;
    return gcd(max(a,b) % min(a,b), min(a,b));
}

ll lcm(ll a, ll b) {
    return a / gcd(a,b) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;

    cin >> n >> m;

    cout << lcm(n,m) / m << endl;

    return 0;

}