/*
 * Problem: "UVa 10158 - War"
 *  Author: "Jia_coding"
 * 
 *     Tag: 並查集(Union-Find)
**/

#include <bits/stdc++.h>
using namespace std;

int N;

int root[20005], Rank[20005];
int find_root(int x) {
    if (root[x] == x) return x;
    return root[x] = find_root(root[x]);
}

void init() {
    for(int i = 0; i < (N<<1); i++) {
        root[i] = i;
        Rank[i] = 1;
    }
}

void Union(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    if (x != y) {
        if (Rank[x] >= Rank[y]) {
            Rank[x] += Rank[y];
            root[y] = x;
        }
        else {
            Rank[y] += Rank[x];
            root[x] = y;
        }
    }
}

int main() {
    
    while (cin >> N) {
        init();    
        
        int c, u, v;
        while (cin >> c >> u >> v && (c+u+v != 0)) {
            int x_F = find_root(u);
            int x_E = find_root(u+N);
            int y_F = find_root(v);
            int y_E = find_root(v+N);
          
            
            //setFriends
            if (c == 1) {
                if (x_E == y_F || y_E == x_F) printf("-1\n");
                else {
                    Union(x_F, y_F); 
                    Union(x_E, y_E); //朋友的敵人是敵人
                }
            }
            //setEnemies
            if (c == 2) {
                if (x_F == y_F) printf("-1\n");
                else {
                    Union(x_F, y_E); //敵人的敵人是朋友 
                    Union(y_F, x_E);
                }
            }
            
            //are_friends
            if (c == 3) {
                printf("%d\n", (x_F == y_F) ? 1 : 0);
            }
            //are_enemies
            if (c == 4) {
                printf("%d\n", (x_E == y_F || y_E == x_F) ? 1 : 0);
            }
            
            /*
            for (int i = 0; i < 2*N; i++) {
                cout<<root[i]<<" ";
            }cout<<endl;
            cout<<endl;*/
        }
    }
    return 0;
}