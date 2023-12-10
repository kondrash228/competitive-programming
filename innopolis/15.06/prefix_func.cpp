#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    vector<int> pi(s.size() + 1, -1);

    for (int i = 1; i <= s.size(); ++i) {
        int k = pi[i - 1];

        while (k != -1 && s[i - 1] != s[k]) {
            k = pi[k];
        }
        pi[i] = k + 1;
    }

    for (int i = 1; i <= s.size() ; ++i) {
        cout << pi[i] << " ";
    }
    return 0;
}