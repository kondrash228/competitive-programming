#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, num;

    stack<int> st;


    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        st.push(num);
    }


}