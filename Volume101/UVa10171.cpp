/*
 * Problem: "UVa 10171 - Meeting Prof. Miguel..."
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖論(Graph), 最短路徑(Shortest Path), Floyd-Warshall
**/

#include <bits/stdc++.h>
using namespace std;


int G[2][30][30]; //0 = adult, 1 = older

void init () {
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                G[k][i][j] = 1e6;
            }
            G[k][i][i] = 0;
        }
    }
}

int main () {
    int N;
    while (cin >> N && N) {
        init();
        
        int C;
        char Age, connect, X, Y;
        while (N--) {
            cin >> Age >> connect >> X >> Y >> C;
            int tmp = (Age == 'Y') ? 0 : 1;
            int U = X -'A';
            int V = Y -'A';
            if (U == V) continue;
    
            G[tmp][U][V] = C;
            if (connect == 'B') G[tmp][V][U] = C;
        }
        /*
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (G[0][i][j] == 1e6) cout<<"inf ";
                else cout<<G[0][i][j]<<" ";
            }cout<<endl;
        }cout<<endl;
        */

        //Floyd-Warshall
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    G[0][i][j] = min(G[0][i][k] + G[0][k][j], G[0][i][j]);
                    G[1][i][j] = min(G[1][i][k] + G[1][k][j], G[1][i][j]);
                }   
            }   
        }
        
        char NY, NO;
        cin >> NY >> NO;
        int NYU = NY - 'A';
        int NOU = NO - 'A';
        int ans = 1e6, idx = 27;
        for (int i = 0; i < 26; i++) {
            ans = min(G[0][NYU][i] + G[1][NOU][i], ans);
        }
        if (ans == 1e6) printf("You will never meet.\n");
        else {
            printf("%d", ans);
            for (int i = 0; i < 26; i++) {
                if (ans == G[0][NYU][i] + G[1][NOU][i]) printf(" %c", i + 'A');
            }
            printf("\n");
        }
    }
    return 0;
}