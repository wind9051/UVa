//UVA13301 Impossible Communication
#include <bits/stdc++.h>
using namespace std;

int n, cnt;

vector<vector<int>> E(50005); // 邊鏈結表
vector<vector<int>> E_R(50005); // 邊反向鏈結表

vector<bool> Vis(50005, 0); // 探訪標記 
vector<bool> Vis_R(50005, 0); // 探訪反向標記

stack<int> stk; // 拓樸排序

void init(int n) {
    for (int i = 1; i <= n; i++) {
        E[i].clear();
        E_R[i].clear();
        Vis[i] = 0;
        Vis_R[i] = 0;
    }
}

void DFS(int u) { 
    Vis[u] = 1;
    for (auto v : E[u]) {
        if (!Vis[v]) DFS(v);
    }
    stk.push(u);
}

void DFS_R(int v) { 
    Vis_R[v] = 1;
    for (auto u : E_R[v]) {
        if (!Vis_R[u]) DFS_R(u);
    }
}

void SCC() { // find strongly connected components
    cnt = 0;
    for (int u = 1; u <= n; u++) { // perform DFS on the original graph
        if (!Vis[u]) DFS(u);
    }

    //拓樸排序反向遍歷
    while (stk.size()) { 
        int v = stk.top(); stk.pop();
        if (!Vis_R[v]) { 
            DFS_R(v);
            cnt++; // 強連通數量
        }
    }
}

int main () {
    int m;
    while (cin >> n >> m) { 
        init(n);
        
        int k, u, v;
        for (int i = 0; i < m; i++) { 
            cin >> k;
            if (k == 1) { // 單向邊
                cin >> u >> v;
                E[u].push_back(v);
                E_R[v].push_back(u);
            }
            else { // 雙向邊
                cin >> u >> v;
                E[u].push_back(v);
                E[v].push_back(u);
                E_R[u].push_back(v);
                E_R[v].push_back(u);
                for (int j = 2; j < k; j++) {
                    u = v;
                    cin >> v;
                    E[u].push_back(v);
                    E[v].push_back(u);
                    E_R[u].push_back(v);
                    E_R[v].push_back(u);
                }
            }
        }
        
        SCC(); 
        
        if (cnt == 1) printf("YES\n"); 
        else printf("NO\n");
    }
    return 0;
}