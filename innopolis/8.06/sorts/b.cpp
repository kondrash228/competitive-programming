#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> a(n);
    vector<int> tmp(10);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        tmp[a[i]]++;
    }

    for (int i = 9; i >= 0; --i) {
        for (int j = 0; j < tmp[i]; ++j) {
            cout << i;
        }
    }
}