/*
 * Problem: "UVa 10959 - The Party, Part I"
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖(Graph), BFS
 * 
 *    Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1900
**/

#include<bits/stdc++.h>
using namespace std;

#define MAX 1005

void BFS(int P, vector<vector<bool>> & edge, vector<int> & dis) {
	queue<int> Q;
    Q.push_back(0);
	dis[0] = 0;
    while (!Q.empty()){
        int cur = Q.front(); Q.pop();
        for (int nxt = 0 ; nxt < P ; nxt++) {
            if (edge[cur][nxt] && dis[nxt] == -1){
                dis[nxt] = dis[cur] + 1;
                Q.push(nxt);
            }
        }
    }
}

int main() {
    int t;
	cin >> t;
    while (t--) {
        int P, D;
		cin >> P >> D;

        vector<vector<bool>> edge(MAX, vector<bool>(MAX, 0));
        for (int i = 0, u, v; i < D; i++) {
            cin >> u >> v;
            edge[u][v] = edge[v][u] = true;
        }

        vector<int> dis(MAX, -1);
		BFS(P, edge, dis);

		for (int i = 1 ; i < P; i++) {
			cout << dis[i] << endl;
		}
        if (t) printf("\n");
	}
	return 0;
}
