/*
 * Problem: "UVa 10189 - Minesweeper"
 *  Author: "Jia_coding"
 * 
 *     Tag: 模擬(Simulation), 棋盤(Board), 踩地雷(Minesweeper)
**/

#include <bits/stdc++.h>
using namespace std;

int N, M;
int G[105][105];
void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            G[i][j] = 0;
        }
    }
}

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1,  0, 0,  1, 1, 1};

bool inGrid(int x, int y) {
	return (0 <= x) && (x < M) && (0 <= y) && (y < N);
}

int main() {
    int Case = 0;
    while (cin >> N >> M && (N+M != 0)) {
        init();
        string S;
        for (int i = 0; i < N; i++) {
            cin >> S;
            for (int j = 0; j < M; j++) {
                if (S[j] == '*') {
                    G[i][j] = -1;
                    for (int k = 0; k < 8; k++) {
                        int y = i + dy[k];
                        int x = j + dx[k];
                        if (inGrid(x, y) && G[y][x] != -1) G[y][x]++;
                    }
                }
            }
        }
        
        if (Case) printf("\n");
        
        printf("Field #%d:\n", ++Case);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (G[i][j] == -1) cout << '*';
                else printf("%d", G[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}