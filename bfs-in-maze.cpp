// For: BFS
// Ref: abc007c in AtCoder

#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    char maze[50][50] = {};
    int d[100][100] = {};

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> maze[i][j];

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            d[i][j] = -1;

    queue<pair<int,int> > q;
    q.push(make_pair(sx - 1, sy - 1));
    d[sy - 1][sx - 1] = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if (x < 0 || y < 0 || x >= C || y >= R) continue;
            if (maze[y][x] == '.' && d[y][x] == -1) {
                q.push(make_pair(x, y));
                d[y][x] = d[p.second][p.first] + 1;
            }
        }
    }

    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++)
    //         cout << d[i][j] << ' ';
    //     cout << endl;
    // }

    cout << d[gy - 1][gx - 1] << endl;

    return 0;
}
