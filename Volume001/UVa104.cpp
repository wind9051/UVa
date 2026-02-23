/*
 * Problem: "UVa 104 - Arbitrage"
 *  Author: "Jia_coding"
 * 
 *     Tag: Floyd
**/

#include <bits/stdc++.h>
using namespace std;

int n;
double DP[21][20][20];   // dp[k][i][j]: 用恰好 k 次交易，從 i 到 j 的最大乘積
int pre[21][20][20];     // pre[k][i][j]: 到 j 前一個貨幣

void init() {
    memset(DP, 0, sizeof(DP));
    memset(pre, -1, sizeof(pre));
}

void printPath(int step, int start) {
    vector<int> path;
    int idx = start;
    while(step > 0) {
        path.push_back(idx);
        idx = pre[step][start][idx];
        step--;
    }
    path.push_back(start);
        
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++) {
        if (i != 0) cout <<" ";
        
        cout << path[i] +1;
    }
    cout << "\n";
}

void printDP(int step) {
    cout << "step: "<< step << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ",DP[step][i][j]);
            
        }
        cout <<endl;
    }
    cout <<endl;
}

void floyd() {
    for (int step = 2; step <= n; step++) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    double val = DP[step - 1][i][k] * DP[1][k][j];
                    if (val > DP[step][i][j]) {
                        DP[step][i][j] = val;
                        pre[step][i][j] = k;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (DP[step][i][i] > 1.01) {
                printPath(step, i);
                return;
            }
        }
    }
    
    cout << "no arbitrage sequence exists\n";
}

int main() {
    while (cin >> n) {
        init();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) DP[1][i][j] = 1.0;
                else cin >> DP[1][i][j];
            }
        }
        
        floyd();
    }
    return 0;
}
