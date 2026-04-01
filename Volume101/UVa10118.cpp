/*
 * Problem: "UVa 10118 - Free Candies"
 *  Author: "Jia_coding"
 * 
 *     Tag: DP, DFS（回溯）
**/

#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> top;
vector<vector<int>> a;
vector<vector<vector<vector<int>>>> dp;

int dfs(int cnt, vector<bool> & basket) {
    int &res = dp[top[0]][top[1]][top[2]][top[3]];

    if (res != -1) return res;
    if (cnt == 5) return 0;

    int tmp = 0;
    for (int i = 0; i < 4; i++) {
        if (top[i] == n) continue;

        top[i]++;
        
        int cur = a[top[i]][i];

        if (basket[cur]) {
            basket[cur] = 0;

            tmp = max(tmp, dfs(cnt-1, basket) + 1);

            basket[cur] = 1;
        }
        else {
            basket[cur] = 1;

            tmp = max(tmp, dfs(cnt+1, basket));

            basket[cur] = 0;
    
        }

        top[i]--;
    }

    return res = tmp;
}

int main () {
    while (cin >> n && n) {
        // init()
        top.assign(5, 0);
        a.assign(n+1, vector<int>(4, 0));
        dp.assign(n+1 , vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -1))));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> a[i][j];
            }
        }

        vector<bool> basket(25, 0);

        cout << dfs(0, basket) << endl;
    }
    return 0;
}