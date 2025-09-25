/*
 * Problem: "UVa 291 - The House Of Santa Claus"
 *  GitHub: "https://github.com/wind9051/UVa"
 *  Notion: "https://titanium-cylinder-f1d.notion.site/00291-272d4158fd1580eaa38bda000a460068?source=copy_link"
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖論, DFS(回溯)
**/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G(6, vector<int>(6));
void init_G() {
    G = {{0,0,0,0,0,0},
         {0,0,1,1,0,1},
         {0,1,0,1,0,1},
         {0,1,1,0,1,1},
         {0,0,0,1,0,1},
         {0,1,1,1,1,0}
        };
}

int cnt = 0;
vector<int> Path;
void DFS(int cur) {
    if (Path.size() >= 8) {
        cout << "1";
        for (int i = 0; i < 8; i++) {
            cout << Path[i];
        }
        cout << endl;
        return;
    }
    for (int v = 1; v <= 5; v++) {
        if (G[cur][v]) {
            G[cur][v] = G[v][cur] = 0;
            Path.push_back(v);
            
            DFS(v);
            
            G[cur][v] = G[v][cur] = 1;
            Path.pop_back();
        }
    }
}


int main() {
    init_G();
    
    DFS(1);
    
    /*
    for (int i = 1; i <= 1; i++) {
        Path.push_back(i);
        DFS(i, Vis);  
        Path.pop_back();
    }
    */
    return 0;
}
