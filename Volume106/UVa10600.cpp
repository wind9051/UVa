/*
 * Problem: "UVa 10600 - ACM Contest and Blackout"
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖論(Graph), 最小生成樹(MST), 克魯斯克爾演算法(Kruskal's Algorithm)
**/

#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w, enable;
} E[10005];

int n, m;

bool cmp(edge & a, edge & b) {
    return a.w < b.w;
}

int root[10005], Rank[10005];

void init() {
    for(int i = 0; i <= n; i++) {
        root[i] = i, Rank[i] = 1; 
    }
}

int find_root(int x) {
    if (root[x] == x) return x;
    return root[x] = find_root(root[x]);
}

int ontree[10005];
void kruskal(int & cost, int & idx) {
    for (int i = 0; i < m; i++) {
        int x = find_root(E[i].u);
        int y = find_root(E[i].v);
        if (x != y) {
            if (Rank[x] > Rank[y]) {
                Rank[x] += Rank[y];
                root[y] = x;
            }
            else {
                Rank[y] += Rank[x];
                root[x] = y;
            }

            ontree[idx++] = i;
            cost += E[i].w;
        }
    }
}

void sec_kruskal(int & mincost, int & idx) {
    for (int i = 0; i < idx; i++) {
        init(); 
        int cost = 0, cnt = 0;
        
        E[ontree[i]].enable = 1;

        for (int j = 0; j < m; j++) {
            if (!E[j].enable) {
                int x = find_root(E[j].u);
                int y = find_root(E[j].v);
                if (x != y) {
                    if (Rank[x] > Rank[y]) {
                        Rank[x] += Rank[y];
                        root[y] = x;
                    }
                    else {
                        Rank[y] += Rank[x];
                        root[x] = y;
                    }
                    cost += E[j].w;
                    cnt++;
                }
            }
        }
        E[ontree[i]].enable = 0;

        if (mincost > cost && cnt == n - 1) {
            mincost = cost;
        }
    }
}

int main() {
	int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> E[i].u >> E[i].v >> E[i].w;
        }
        sort(E, E+m, cmp);

        init();

        int cost = 0, idx = 0;

        //kruskal
        kruskal(cost, idx);
        printf("%d ", cost);

        //sec_kruskal
        int mincost = 0xfffffff;
        sec_kruskal(mincost, idx);
        printf("%d\n", mincost);
    }
	return 0;
}
