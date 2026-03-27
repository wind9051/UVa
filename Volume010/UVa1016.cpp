/*
 * Problem: "UVa 1016 - Silly Sort"
 *  Author: "Jia_coding"
 * 
 *     Tag: 排序（循環）
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, Cas = 1;
    while (cin >> n && n) {
        
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        vector<int> B = A;
        sort(B.begin(), B.end());

        int globalMin = B[0];

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) pos[B[i]] = i;

        vector<bool> vis(n, false);
        long long totalCost = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || pos[A[i]] == i) continue;

            int cur = i;
            long long cycleSum = 0;
            int cycleMin = INT_MAX, cycleSize = 0;
            while (!vis[cur]) {
                vis[cur] = true;
                
                int val = A[cur];
                cycleMin = min(cycleMin, val);
                cycleSum += val;
                cur = pos[val];
                cycleSize++;
            }

            if (cycleSize > 0) {
                // 方法1：循環內直接交換
                ll cost1 = cycleSum - cycleMin + (cycleSize - 1) * cycleMin;
                // 方法2：利用全局最小值
                ll cost2 = 2 * (cycleMin + globalMin) + cycleSum - cycleMin + (cycleSize - 1) * globalMin;
                totalCost += min(cost1, cost2);
            }
        }

        cout << "Case " << Cas++ << ": " << totalCost << "\n\n";
    }
    return 0;
}
