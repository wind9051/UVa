/*
 * Problem: "UVa 12319 - Edgetown's Traffic Jams"
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖論(Graph), 最短路徑(Shortest Path), Floyd-Warshall
**/

#include <bits/stdc++.h>
using namespace std;

const int inf = 1e6;

int N;
int G[2][105][105]; //0 = old, 1 = new

void init () {
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                G[k][i][j] = inf;
            }
            G[k][i][i] = 0;
        }
    }
}

void print(int G[105][105]) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (G[i][j] == 1e6) cout<<"inf ";
            else printf("%3d ", G[i][j]);
        }
        cout<<endl;
    }
    cout<<endl;
}

int main () {
    while (cin >> N && N) {
        cin.ignore();
        
        init();
        
        string s;
        int u, v;
        for (int i = 0; i < N; i++) {
            getline(cin, s);
            stringstream ss(s);
            
            ss >> u;
            while (ss >> v) {
                G[0][u][v] = 1;
                //G[0][v][u] = 1;
            }
        }
        
        for (int i = 0; i < N; i++) {
            getline(cin, s);
            stringstream ss(s);
            
            ss >> u;
            while (ss >> v) {
                G[1][u][v] = 1;
            }
        }
        //print(G[1]);
        //print(G[0]);

        //Floyd-Warshall
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    G[0][i][j] = min(G[0][i][k] + G[0][k][j], G[0][i][j]);
                    G[1][i][j] = min(G[1][i][k] + G[1][k][j], G[1][i][j]);
                }   
            }   
        }
        //print(G[0]);
        //print(G[1]);
        
        int A, B;
        cin >> A >> B;
        
        //d` <= Ad + B
        bool flag = 0;
        for (int i = 1; i <= N && !flag; i++) {
            for (int j = 1; j <= N && !flag; j++) {
                //cout<<A * G[0][i][j] + B <<" ";
                //cout<<G[0][i][j] <<" "<<G[1][i][j]<<endl;
                if (i == j) continue;
                if (G[1][i][j] > (A * G[0][i][j] + B)) flag = 1;
            }
        }
        
        if (flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}