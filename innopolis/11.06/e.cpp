#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }

    vector<int> in, out;
    int cnt0, cnt1;
    for (int i = 0; i < n; ++i) {
        cnt0 = 0, cnt1 = 0;

        for (int j = 0; j < n; ++j) {
            cnt0 += v[i][j], cnt1 += v[j][i];
        }

        if (cnt0 == 0) {
            out.push_back(i + 1);
        }
        if (cnt1 == 0) {
            in.push_back(i + 1);
        }
    }

    cout << in.size() << " ";

    for (int x: in) {
        cout << x << " ";
    }

    cout << "\n" << out.size() << " ";
    for (int x: out)
        cout << x << " ";
}
