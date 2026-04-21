/*
 * Problem: "UVa 10130 - SuperSale"
 *  Author: "Jia_coding"
 *
 *     Tag: 動態規劃(DP), 01背包(Knapsack)
 *
**/

#include <bits/stdc++.h>
using namespace std;

int N, G, MW;

struct Object {
    int P, W;
};

int main () {
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<Object> val(N);
        for (int i = 0; i < N; i++) {
            cin >> val[i].P >> val[i].W;
        }
        
        cin >> G;
        int sum = 0;
        while (G--) {
            cin >> MW;
            vector<int> DP(35, 0);
            for (int n = 0; n < N; n++) {
                for (int now = MW; now >= val[n].W; now--) {
                    DP[now] = max(DP[now-val[n].W] + val[n].P, DP[now]);
                }
            }
            
            int maxn = 0;
            for (int now = 0; now <= MW; now++) {
                maxn = max(maxn, DP[now]);
            }
            
            sum += maxn;
        }
        printf("%d\n", sum);
    }
    return 0;
}