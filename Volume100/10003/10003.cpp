/*
 * Problem: "UVa10003 - Cutting Sticks"
 *  Author: "Jia_coding"
 *    Date: "2025/03/15"
 *     Tag: DP
 *        : 動態規劃
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int L;
    while (cin >> L && L != 0) {
        int n;
        cin >> n; 

        vector<int> cost(n + 2, 0); 
        for (int i = 1; i <= n; i++) {
            cin >> cost[i]; 
        }
        cost[n + 1] = L; 

        vector<vector<int>> DP(n + 2, vector<int>(n + 2, 0)); 
        for (int w = 2; w <= n + 1; w++) { 
            for (int l = 0; l <= n; l++) { 
                int r = l + w; 
                if (r > n + 1) break;

                DP[l][r] = 10000; 

                for (int m = l + 1; m < r; m++) {
                    DP[l][r] = min(DP[l][m] + DP[m][r] + cost[r] - cost[l], DP[l][r]);
                }
            }
        }
        printf("The minimum cutting is %d.\n", DP[0][n + 1]);
    }
    return 0;
}