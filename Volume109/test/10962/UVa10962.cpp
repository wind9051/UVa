/*
 * Problem: "UVa 10962 - Don Giovanni's Last Dinner"
 *  Author: "Jia_coding"
 * 
 *     Tag: 精度
 * 
 *    Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1903
**/

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-8

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, r, N, C;
        cin >> R >> r >> N >> C;

        int s, g;
        vector<double> totalEatTime(N+1, 0);
        vector<double> startTime(N+1, 0), endTime(N+1, 0);
        for (int i = 1; i <= N; i++) {
            cin >> s >> g;
            totalEatTime[i] = totalEatTime[i - 1] + 1.0 * g / R;
            startTime[i] = max(endTime[i - 1], totalEatTime[i]);
            endTime[i] = startTime[i] + 1.0 * (s - g) / r;
        }
        
        int L = 1;
        for (int i = 0; i < C; i++) {
            int callT;
            cin >> callT;
            while (L <= N && endTime[L] + EPS < callT) L++;
            
            if (L > N) {
                printf("clear\n");
                continue;
            }
            
            if (callT < startTime[L] - EPS) printf("clear\n");
            else if (startTime[L] - EPS <= callT && callT <= endTime[L] + EPS) printf("full\n");
            else printf("clear\n");
        }
        if (t) printf("\n");
    }
    return 0;
}