/*
 * Problem: "UVa 10034 - Freckles"
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖論(Graph), 最小生成樹(MST), 克魯斯克爾演算法(Kruskal's Algorithm), 歐幾里得距離（Euclidean Distance）
**/

#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
} P[105];


struct edge {
    int u, v;
    double w;
} E[5005];

int n, idcnt;

bool cmp(edge & a, edge & b) {
    return a.w < b.w;
}

int root[5005], Rank[5005];

void init() {
    for(int i = 0; i <= 5000; i++) {
        root[i] = i, Rank[i] = 1; 
    }
}

int find_root(int x) {
    if (root[x] == x) return x;
    return root[x] = find_root(root[x]);
}

//歐幾里得距離（Euclidean Distance）
double dist(double x1, double x2, double y1, double y2) {
    return sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
}

void kruskal() {
    init();

    double sum = 0.0;
    for (int i = 0; i < idcnt; i++) {
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
            sum += E[i].w;
        }
    }
    printf("%.2f\n", sum);
}

int main() {
	int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> P[i].x >> P[i].y;
        }
        
        idcnt = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i + 1; j < n; j++) {
                E[idcnt].u = i;
                E[idcnt].v = j;
                E[idcnt++].w = dist(P[i].x, P[j].x, P[i].y, P[j].y);
            }
        }
        sort(E, E+idcnt, cmp);

        //kruskal
        kruskal();

        if (t) printf("\n");
    }
	return 0;
}
