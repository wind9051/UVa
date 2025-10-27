/*
 * Problem: "UVa 10842 - Traffic Flow"
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖論(Graph), 最大生成樹(MST), 克魯斯克爾演算法(Kruskal's Algorithm)
**/

#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
} E[10005];

int n, m;

bool cmp(edge & a, edge & b) {
    return a.w > b.w;
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

void kruskal() {
    int sum = 0;
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
            sum = E[i].w;
        }
    }
    printf("%d\n", sum);
}

int main() {
	int t, Case = 1;
    cin >> t;
    while (t--) {
        
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> E[i].u >> E[i].v >> E[i].w;
        }
        sort(E, E+m, cmp);

        init();

        //kruskal
        printf("Case #%d: ", Case++);
        kruskal();
    }
	return 0;
}
