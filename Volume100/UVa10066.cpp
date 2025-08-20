/*
 * Problem: "UVa 10066 - The Twin Towers"
 *  Author: "Jia_coding"
 *
 *     Tag: 動態規劃(DP), 最長公共子序列(LCS)
 *
**/

#include <bits/stdc++.h>
using namespace std;

int main () {
    int x, y, Case = 1;
    while (cin >> x >> y && x && y) {
        vector<int> N1(x, 0);
        vector<int> N2(y, 0);
        for (int i = 0; i < x; i++) cin >> N1[i];
        for (int i = 0; i < y; i++) cin >> N2[i];
        
        vector<vector<int>> LCS(x+1, vector<int>(y+1, 0));
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (N1[i-1] == N2[j-1]) LCS[i][j] = LCS[i-1][j-1] + 1;
                else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
        printf("Twin Towers #%d\n", Case++);
        printf("Number of Tiles : %d\n\n", LCS[x][y]);
    }
    return 0;
}