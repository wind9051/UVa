/*
 * Problem: "UVa 10500 - Robot maps"
 *  Author: "Jia_coding"
 *    Date: "2025/03/13"
 *     Tag: Matrix, Grid, Flood Fill, DFS
 *        : 矩陣, 網格, 洪水填滿, 深度優先搜尋
**/

#include <iostream>
#include <vector>
using namespace std;
 
void print_border(int n) {
    cout << "|";
    for (int i = 0; i < n; i++) {
        cout << "---|";
    }
    cout << endl;
}
 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void mark_scan(vector<vector<bool>> &Scan, int x, int y) {
    Scan[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        Scan[nx][ny] = true;
    }
}

int main() {
    int n, m, x, y;  
    while (cin >> n >> m && n && m) {
        vector<vector<char>> G(12, vector<char>(12, '#'));
        vector<vector<bool>> Vis(12, vector<bool>(12, false));
        vector<vector<bool>> Scan(12, vector<bool>(12, false));

        cin >> x >> y;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> G[i+1][j+1];
            }
        }
        //Simulation 
        int moves = 0;
        while (true) {
            Vis[x][y] = true;
            mark_scan(Scan, x, y);
            if (G[x-1][y] == '0' && !Vis[x-1][y]) x--;
            else if (G[x][y+1] == '0' && !Vis[x][y+1]) y++;
            else if (G[x+1][y] == '0' &&!Vis[x+1][y]) x++;
            else if (G[x][y-1] == '0' && !Vis[x][y-1]) y--;
            else break;

            moves++;
        }
        //print
        cout << endl;
        print_border(m);
        for (int i = 0; i < n; i++) {
            cout << "|";
            for (int j = 0; j < m; j++) {
                cout << " ";
                if (!Scan[i+1][j+1]) cout << "?";
                else cout << G[i+1][j+1];
                cout << " ";
                cout << "|";
            }
            cout << endl;
            print_border(m);
        }
        cout << endl;
        cout << "NUMBER OF MOVEMENTS: " << moves << endl;
    }
    return 0;
}