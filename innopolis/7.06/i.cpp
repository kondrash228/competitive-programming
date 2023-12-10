#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        int move_city = -1;

        for (int j = i+1; j < n; ++j) {

            if (a[j] < a[i]) {
                move_city=j;
                break;
            }
        }

        cout << move_city << " ";
    }


}