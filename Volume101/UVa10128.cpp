/*
 * Problem: "UVa 10128 - Queue"
 *  Author: "Jia_coding"
 * 
 *     Tag: DP, 排列
**/

#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;

void initDP() {
    dp.assign(15, vector<vector<int>>(15, vector<int>(15, 0)));
    
    dp[1][1][1] = 1;
    for (int i = 2; i <= 13; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= i; k++) {
                dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j][k-1] + (i-2) * dp[i-1][j][k];
            }
        }
    }
}

int main () {
    initDP();
    
    int t;
    cin >> t;
    while (t--) {
        int N, P, R;
        cin >> N >> P >> R;
        
        
        cout << dp[N][P][R] << endl;
    }
    return 0;
}