#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string cmd;
    int num;
    set<int> st;

    while (cin >> cmd) {
        // cout << cmd << "\n";
        if (cmd == "insert") {
            cin >> num;
            st.insert(num);

        } else if (cmd == "delete") {
            cin >> num;
            st.erase(num);

        } else if (cmd == "exists") {
            cin >> num;
            cout << ((st.count(num)) ? "true\n" : "false\n");
        } else if (cmd == "next") {
            cin >> num;
            if ((st.upper_bound(num)) != st.end()) {
                cout << *(st.upper_bound(num)) << "\n";
            } else {
                cout << "none" << "\n";
            }

        } else if (cmd == "prev") {
            cin >> num;
            auto prev = st.lower_bound(num);
            if (prev != st.begin()) {
                --prev;
                cout << *prev << "\n";
            } else {
                cout << "none" << "\n";
            }

        }
    }
}