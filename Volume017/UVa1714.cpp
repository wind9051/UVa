/*
 * Problem: "UVa 1714 - Keyboarding"
 *  GitHub: "https://github.com/wind9051/UVa"
 *  Author: "Jia_coding"
 * 
 *     Tag: 棋盤, BFS
**/

#include <bits/stdc++.h>
using namespace std;

int r, c;
struct Node {
    int x, y, idx, step;
};

int DX[4] = {1, -1, 0, 0};
int DY[4] = {0, 0, 1, -1};

bool inGrid(int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c;
}

int main() {
    while (cin >> r >> c) {
        string s;
        vector<vector<char>> G(r, vector<char>(c, '!'));
        for (int i = 0; i < r; i++) {
            cin >> s;
            for (int j = 0; j < c; j++) {
                G[i][j] = s[j];
            }
        }
        
        cin >> s;
        s += "*"; // end mark

        int ans = INT_MAX;
        vector<vector<int>> Vis(55, vector<int>(55, -1));

        //BFS
        queue<Node> q;
        q.push({0, 0, 0, 0}); //(0,0)
        while (!q.empty()) {
            Node cur = q.front(); q.pop();
            int x = cur.x, y = cur.y, idx = cur.idx, step = cur.step;

            if (G[x][y] == s[idx]) {
                if (idx == s.size() - 1) {
                    ans = step + 1;
                    break;
                }
                if (Vis[x][y] < idx+1) {
                    Vis[x][y] = idx+1;
                    q.push({x, y, idx+1, step+1});
                }
            }
            
            for (int k = 0; k < 4; k++) {
                int nx = x + DX[k];
                int ny = y + DY[k];
                // Keep jumping while same character
                while (inGrid(nx, ny)  && G[nx][ny] == G[x][y]) {
                    nx += DX[k];
                    ny += DY[k];
                }
                
                if (!inGrid(nx, ny)) continue;
                if (Vis[nx][ny] < idx) {
                    Vis[nx][ny] = idx;
                    q.push({nx, ny, idx, step+1});
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
