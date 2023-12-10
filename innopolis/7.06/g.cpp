#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<pair<int, int>> st;

    int n, cnt = 0, x;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (st.empty()) {
            st.push(make_pair(x, 1));
        } else {
            if (st.top().first == x) {
                st.top().second++;
            } else {

                if (st.top().second >= 3) {
                    cnt += st.top().second;
                    st.pop();
                }

                if (!st.empty() && st.top().first == x)
                    st.top().second++;
                else
                    st.push(make_pair(x, 1));
            }
        }
    }

    if (st.top().second >= 3) {
        cnt += st.top().second;
        st.pop();
    }

    cout << cnt << "\n";
    return 0;
}