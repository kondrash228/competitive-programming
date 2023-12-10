#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    vector<bool> sieve(b + 1);

    for (int i = 2; i <= b; ++i) {
        if (!sieve[i]) {
            for (int j = 2 * i; j <= b; j += i) { // если начать с i * i то ускоряется код
                sieve[j] = true;
            }
        }
    }

    for (int i = a; i <= b; ++i) {
        if (!sieve[i] && i != 1) {
            cout << i << " ";
        }
    }

    return 0;
}