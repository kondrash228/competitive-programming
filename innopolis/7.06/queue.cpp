#include <iostream>
#include <stack>
#include <queue>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << " " << q.back() << "\n";

    q.pop();
    cout << q.front() << " " << q.back() << "\n";
}