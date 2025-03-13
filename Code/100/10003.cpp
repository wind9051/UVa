/*
 * Title:  "UVa10003 - Cutting Sticks"
 * Author: "Jia_coding"
 * Date:   "2024/08/16"
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int L;
    while (cin >> L && L != 0) {
        int n;
        cin >> n; // 读取切割点数

        vector<int> cost(n + 2, 0); // 存储每个切割点的成本，n+2是因为有起始和结束点
        for (int i = 1; i <= n; i++) {
            cin >> cost[i]; // 读取每个切割点的成本
        }
        cost[n + 1] = L; // 最后一个切割点是总长度L

        vector<vector<int>> DP(n + 2, vector<int>(n + 2, 0)); // 动态规划数组，n+2 x n+2
        for (int w = 2; w <= n + 1; w++) { // w表示切割段的长度，从2到n+1
            for (int l = 0; l <= n; l++) { // l表示切割段的左端点
                int r = l + w; // 计算右端点
                if (r > n + 1) break;

                DP[l][r] = 10000; // 初始化为一个较大的值

                for (int m = l + 1; m < r; m++) {
                    // 计算切割段[l, r]的最小成本
                    DP[l][r] = min(DP[l][m] + DP[m][r] + cost[r] - cost[l], DP[l][r]);
                }
            }
        }
        printf("The minimum cutting is %d.\n", DP[0][n + 1]);
    }
    return 0;
}
