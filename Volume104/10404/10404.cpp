/*
 * Problem: "UVa 10404 - Bachet’s Game"
 *  Author: "Jia_coding"
 *    Date: "2025/03/14"
 *     Tag: DP, 
 *        : 動態規劃, 博弈
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> Stone(m);
        for (int i = 0; i < m; i++) cin >> Stone[i];

        //DP[i] = 1: Stan wins, DP[i] = 0: Ollie wins
        vector<int> DP(n+1, 0);
        for (int i = 1; i <= n; i++) {
            for (auto s : Stone) {
                if (i - s >= 0 && !DP[i-s]) {
                    DP[i] = 1;
                    break;
                }
            }
        }
        printf("%s\n", (DP[n]) ? "Stan wins" : "Ollie wins");
    }
    return 0;
}