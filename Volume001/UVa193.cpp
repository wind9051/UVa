/*
 * Problem: "UVa 193 - Graph Coloring"
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖(最大獨立集), DFS(回溯)
**/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> G;     
vector<int> bestSet;

void init() {
    G.assign(n+1, vector<int>());
    bestSet.clear();
}

void dfs(int cur, vector<int> &color, vector<int> & curSet) {
    if (cur > n) {
        if (curSet.size() > bestSet.size()) {
            bestSet = curSet;
        }
        return;
    }

    bool canBlack = true;
    for (int v : G[cur]) {
        if (color[v] == 1) { // 相鄰節點已經黑色
            canBlack = false;
            break;
        }
    }

    // Black
    if (canBlack) {
        color[cur] = 1;
        curSet.push_back(cur);
        dfs(cur+1, color, curSet);
        curSet.pop_back();
        color[cur] = 0;
    }

    // White
    dfs(cur+1, color, curSet);
}

int main() {
    int t; 
    cin >> t; 
    while (t--) {
        cin >> n >> m;
        
        init();
        
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        // 0 = useless, 1 = Black, -1 = White
        vector<int> color(n+1, 0), curSet; 
        
        dfs(1, color, curSet);
        
        printf("%d\n", bestSet.size());
        for (int i = 0; i < bestSet.size(); i++) {
            printf("%d%c", bestSet[i], (i == bestSet.size()-1) ? '\n' : ' ');
        }
    }
    return 0;
}
