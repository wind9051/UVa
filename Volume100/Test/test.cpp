/*
 * Problem: "UVa 1099 - Sharing Chocolate"
 *  GitHub: "https://github.com/wind9051/UVa"
 *  Author: "Jia_coding"
 * 
 *     Tag: 狀態壓縮動態規劃(DP - State Compression), 遞迴, 位元遮罩Bitmask, 分治(Divide and Conquer) 
**/

#include <bits/stdc++.h>
using namespace std;

int n;
int piece[105], subsum[1<<15], DP[105][1<<15];
// dp[x][s] 代表是否能將子集 s 的巧克力拼成長邊為 x 的矩形


void init() {
    memset(subsum, 0, sizeof(subsum));
    memset(DP, -1, sizeof(DP));
}


// x: 當前矩形的一邊長度
// s: 當前要切分的巧克力塊集合 (用位元遮罩表示)
bool can_partition(int x, int s) {
    //Vis
    if (DP[x][s] >= 0) return DP[x][s];
    //Count = 1
    if (__builtin_popcount(s) == 1) return 1;

    int y = subsum[s] / x;
    
    for (int S0 = (s-1)&s; S0; S0 = (S0-1) & s) {
        int S1 = S0 ^ s; //捕集

        if (subsum[S0] % x == 0 && subsum[S1] % x == 0) {
            if (can_partition(min(x, subsum[S0]/x), S0) && can_partition(min(x, subsum[S1]/x), S1)) {
                return DP[x][s] = 1;
            }
        }

        if (subsum[S0] % y == 0 && subsum[S1] % y == 0) {
            if (can_partition(min(y, subsum[S0]/y), S0) && can_partition(min(y, subsum[S1]/y), S1)) {
                return DP[x][s] = 1;
            }
        }
    }

    return DP[x][s] = 0;
}

int main () {
    int Case = 1;
    while (cin >> n && n) {
        init();

        int x, y;
        cin >> x >> y;
        for (int i = 0; i < n; i++) {
            cin >> piece[i];
        }

        //subset
        int nbit = (1<<n)-1;
        for (int bit = 0; bit <= nbit; bit++) {
            for (int i = 0; i < n; i++) {
                if ((1<<i) & bit) {
                    subsum[bit] += piece[i];
                }
            }
        }
        
        printf("Case %d: ", Case++);
        if (subsum[nbit] == x*y && can_partition(x, nbit)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}