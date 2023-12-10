#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, cmd, x;
    stack<int> st;

    cin >> n;


    for (int i = 0; i < n; ++i) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> x;
            if (st.empty()) {
                st.push(x);
            } else {
                st.push(min(st.top(), x));
            }
        } else if (cmd == 2) {
            st.pop();
        } else {
            cout << st.top() << "\n";
        }
    }
    return 0;
}