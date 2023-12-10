#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, cmd, num;
    cin >> n;

    priority_queue<int> pq;

    for (int i = 0; i < n; ++i) {
        cin >> cmd;
        if (cmd == 0) {
            cin >> num;
            pq.push(num);
        } else {
            cout << pq.top() << "\n";
            pq.pop();
        }
    }

}