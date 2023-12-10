#include <iostream>
#include <stack>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    stack<char> st;

    string brackets;

    cin >> brackets;

    int cnt = 0;

    for (auto c : brackets) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else {
            if (st.empty()) {
                cnt++;
            }
            else if (c == ')' && st.top() != '(') {
                cnt++;
            }
            else if (c == ']' && st.top() != '[') {
                cnt++;
            }
            else if (c == '}' && st.top() != '{') {
                cnt++;
            }
            else {
                st.pop();
            }
        }
    }


    if (!st.empty()) {
        cnt += st.size();
    }

    cout << cnt;

    return 0;
}