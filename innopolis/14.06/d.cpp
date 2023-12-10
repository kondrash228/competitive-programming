#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, cmd, amount;
    cin >> n;
    string name;

    map<string, int> b;

    for (int i = 0; i < n; ++i) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> name >> amount;
            b[name] += amount;
        } else {
            cin >> name;
            if (b.find(name) == b.end()) {
                cout << "ERROR" << "\n";
            } else {
                cout << b[name] << "\n";
            }
        }
    }

}