/*
 * Problem: "UVa 911 - Multinomial Coefficients"
 *  Author: "Jia_coding"
 * 
 *     Tag: 排組(組合) 多項式
**/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> initCombinations() {
    vector<vector<int>> C(105, vector<int>(105));
    C[0][0] = 1;
    for (int i = 1; i <= 100; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    return C;
} 

int main () {
    vector<vector<int>> C = initCombinations();

    int n, k, r;
    while (cin >> n >> k) {
        int ans = 1;
        while (k--) {
            cin >> r;
            ans *= C[n][r];

            n -= r;
        }
        printf("%d\n", ans);
    }
    return 0;
}