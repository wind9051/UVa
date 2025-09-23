/*
 * Problem: "UVa 1757 - Secret Chamber at Mount Rushmore"
 *  GitHub: "https://github.com/wind9051/UVa"
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖論(Graph), 最短路徑(Shortest Path)- Floyd-Warshall
**/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G(26, vector<int>(26, 0));
        
void init_G() {
    for (int i = 0; i < 26; i++) {
        G[i][i] = 1;
        for (int j = 0; j < 26; j++) {
            if (i != j) G[i][j] = 0;
        }
    }
}

bool reach(string S, string E) {
    if (S.size() != E.size()) return false;
    for (int i = 0; i < S.size(); i++) {
        if (!G[S[i]-'a'][E[i]-'a']) return false;
    }
    return true;
}

int main() {
    int m, n;
    while (cin >> m >> n) {
        init_G();
        
        for (int i = 0; i < m; i++) {
            char u, v;
            cin >> u >> v;
            G[u-'a'][v-'a'] = 1;
        }
        
        
        //Floyd 閉包
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    G[i][j] |= (G[i][k] && G[k][j]);
                }
            }
        }
        
        string S, E;
        for (int i = 0; i < n; i++) {
            cin >> S >> E;
            cout << (reach(S, E) ? "yes\n" : "no\n");
        }
    }
    return 0;
}