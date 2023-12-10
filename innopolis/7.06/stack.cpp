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

    bool check = true;

    for (auto c : brackets) {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else {
            if (st.empty())
                check = false;
            else if (c == ')' && st.top() != '(')
                check = false;
            else if (c == ']' && st.top() != '[')
                    check = false;
            else if (c == '}' && st.top() != '{')
                check = false;
            else
                st.pop();
        }
    }


    if (!st.empty()) {
        check = false;
    }
    cout << (check ? "YES" : "NO");

    return 0;
}