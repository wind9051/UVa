/*
 * Problem: "UVa 1056 - Degrees of Separation"
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖, Floyd
**/

#include <bits/stdc++.h>
using namespace std;

int main () {
    int P, R, Case = 1;
    while (cin >> P >> R && P && R) {
        
        string n1, n2;
        int now = 0, u, v;
        map<string, int> nameid;
        vector<vector<int>> G(55, vector<int>(55, INT_MAX/2));
        
        //Adjacency Matrix
        for (int i = 0; i < R; i++) {
            cin >> n1 >> n2;
            
            if (!nameid.count(n1)) nameid[n1] = now++;
            if (!nameid.count(n2)) nameid[n2] = now++;
            
            u = nameid[n1];
            v = nameid[n2];
            
            G[u][v] = 1;
            G[v][u] = 1;
        }
        
        //Floyd (all pair shortest path)
        for (int k = 0; k < P; k++) {
            for (int i = 0; i < P; i++) {
                for (int j = 0; j < P; j++) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < P; i++) {
            for (int j = i+1; j < P; j++) {
                ans = max(ans, G[i][j]);
            }
        }
        
        if (ans == INT_MAX/2) {
            printf("Network %d: DISCONNECTED\n\n", Case++);
        }
        else{
            printf("Network %d: %d\n\n", Case++, ans);
        }
    }
    
    return 0;
}