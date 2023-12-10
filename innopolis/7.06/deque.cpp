#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

const int MAXAB = 150001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, n1, b;
    cin >> n;

    vector<deque<int>> a(MAXAB);
    string cmd;

    for (int i = 0; i < n; ++i) {
        cin >> cmd;

        if (cmd == "pushfront") {
            cin >> n1 >> b;


            a[n1].push_front(b);
        } else if (cmd == "pushback") {
            cin >> n1 >> b;

            a[n1].push_back(b);
        } else if (cmd == "popfront") {
            cin >> n1;
            cout << a[n1].front() << "\n";

            a[n1].pop_front();
        } else if (cmd == "popback") {
            cin >> n1;
            cout << a[n1].back() << "\n";

            a[n1].pop_back();
        }
    }

    return 0;
}