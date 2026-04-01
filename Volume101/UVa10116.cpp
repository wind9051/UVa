/*
 * Problem: "UVa 10116 - Robot Motion"
 *  Author: "Jia_coding"
 * 
 *     Tag: 棋盤 - 網格
**/

#include <bits/stdc++.h>
using namespace std;

int n, m, step;
vector<vector<char>> G(15, vector<char>(15, ' '));
void DFS(int x, int y, vector<vector<int>>& Vis) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        printf("%d step(s) to exit\n", step);
        return;
    }
    if (Vis[x][y] != -1) {
        printf("%d step(s) before a loop of %d step(s)\n", Vis[x][y]-1, step-Vis[x][y]+1);
        return;
    }
    
    Vis[x][y] = ++step;
    
    if (G[x][y] == 'N') DFS(x-1, y, Vis);
    if (G[x][y] == 'S') DFS(x+1, y, Vis);
    if (G[x][y] == 'E') DFS(x, y+1, Vis);
    if (G[x][y] == 'W') DFS(x, y-1, Vis);
}

int main() {
    int p;
    while (cin >> n >> m >> p && n) {
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < m; j++) {
                G[i][j] = s[j];
            }
        }
        
        vector<vector<int>> Vis(15, vector<int>(15, -1));
        
        step = 0;
        DFS(0, p-1, Vis);
    }
    return 0;
}