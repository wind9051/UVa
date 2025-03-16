/*
 * Problem: "UVa10004 - Bicoloring"
 *  Author: "Jia_coding"
 *    Date: "2025/03/15"
 * 
 *     Tag: Graph, BFS, Coloring
 *          圖, 廣度優先搜尋, 著色
 * 
 * Reference: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=945
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int v;
    while (cin >> v && v != 0) {
        int n;
        cin >> n;

        vector<vector<bool>> M(v, vector<bool>(v, false));
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            M[u][v] = M[v][u] = true;
        }
        
        
        queue<int> Q;
        vector<int> color(n, -1);
        
        Q.push(0); 
        color[0] = 0;
        bool flag = 1; 
        while (!Q.empty()) {
            int now = Q.front(); Q.pop();
            for (int i = 0; i < n && flag; i++) {
                if (M[now][i]) {
                    if (color[i] == -1) {
                        
                        color[i] = color[now] == 1 ? 0 : 1;
                        Q.push(i);
                    }
                    else {
                        if (color[now] == color[i]) {
                            flag = 0;
                        }
                    }
                }
                
            }
        }
        if (flag) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
    return 0;
}