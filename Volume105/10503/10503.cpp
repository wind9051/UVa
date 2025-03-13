/*
 * Problem: "UVa 10503 - The dominoes solitaire"
 *  Author: "Jia_coding"
 *    Date: "2025/03/13"
 *     Tag: DFS, Backtracking 
 *        : 深度優先搜尋, 回溯
**/

#include<bits/stdc++.h>
using namespace std;

int n, m;
bool flag = 0;
pair<int, int> S, E;
vector<bool> Vis(15);
vector<pair<int, int>> Dom(15);

void DFS(int now, int deep) {
    if (flag) return;
    if (deep == n) {
        if (now == E.first) {
            flag = true;
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        if (!Vis[i]) {
            Vis[i] = true;
            if (now == Dom[i].first) DFS(Dom[i].second, deep+1);
            if (now == Dom[i].second) DFS(Dom[i].first, deep+1);
            Vis[i] = false;
        }
    }
    return;
}

int main() {
    while (cin >> n >> m && m) {
        cin >> S.first >> S.second >> E.first >> E.second;
        
		for (int i = 0; i < m; i++) {
		    cin >> Dom[i].first >> Dom[i].second;
		    Vis[i] = false;
		}
		flag = false;
		DFS(S.second, 0);
		
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}