#include <iostream>
#include <vector>

using namespace std;


int main() {
    int x;
    vector<int> cnt(101);

    while (cin >> x) cnt[x]++;

    for (x = 0; x < 101; x++) {
        for (int i = 0; i < cnt[x]; ++i)
            cout << x << " ";
    }

}