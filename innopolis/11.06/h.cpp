#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs();

int main() {
    int n, x0, y0, x1, y1;
    cin >> n >> x0 >> y0 >> x1 >> y1;
    x0--, y0--, x1--, y1--;

    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    q.push({})


}