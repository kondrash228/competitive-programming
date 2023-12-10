#include <iostream>
#include <queue>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    queue<int> q;

    int n,n1;
    cin >> n;

    char cmd;


    for (int i = 0; i < n; ++i) {
        cin >> cmd;


        if (cmd == '+') {
            cin >> n1;
            q.push(n1);
        } else {
            cout << q.front() << "\n";
            q.pop();
        }
    }

    return 0;
}