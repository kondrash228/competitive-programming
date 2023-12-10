#include <iostream>
#include <stack>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;

    cin >> n;

    stack<int> st;

    int cmd, n1;
    for (int i = 0; i < n; ++i) {
        cin >> cmd;

        if (cmd == 1) {
            cin >> n1;
            st.push(n1);
        } else {
            cout << st.top() << "\n";
            st.pop();
        }

    }

    return 0;
}