/*
 * Problem: "UVa 10147 - Highways"
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖論(Graph), 最小生成樹(MST), 克魯斯克爾演算法(Kruskal's Algorithm), 歐幾里得距離（Euclidean Distance）
**/

#include <bits/stdc++.h>
using namespace std;

int N, M, idcnt, treecnt;
int root[5005], Rank[5005];

struct point {
    int x, y;
} P[755];

struct edge {
    int u, v; 
    double w;
} E[800*800];

bool cmp(edge & a, edge & b) {
    return a.w < b.w;
}

void init() {
    for(int i = 0; i <= N; i++) {
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
    //double sum = 0.0;
    treecnt = 0;
    for (int i = 0; i < idcnt; i++) {
        int x = find_root(E[i].u);
        int y = find_root(E[i].v);
        if (x != y) {
            if (E[i].w) printf("%d %d\n", E[i].u, E[i].v);
            if (Rank[x] > Rank[y]) {
                Rank[x] += Rank[y];
                root[y] = x;
            }
            else {
                Rank[y] += Rank[x];
                root[x] = y;
            }
            treecnt++;
            //sum += E[i].w;
        }
        
    }
    //printf("%.2f\n", sum);
}

int main() {
	int t;
    cin >> t;
    while (t--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> P[i].x >> P[i].y;
        }

        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> E[i].u >> E[i].v;
            E[i].w = 0;
        }

        init();

        idcnt = M;

        kruskal();
    

        if (treecnt == N - 1) {
            printf("No new highways need\n");
        }
        else {
            idcnt = 0;
            for (int i = 1; i <= N-1; i++) {
                for (int j = i + 1; j <= N; j++) {
                    E[idcnt].u = i;
                    E[idcnt].v = j;
                    E[idcnt++].w = dist(P[i].x, P[j].x, P[i].y, P[j].y);
                }
            }
            sort(E, E+idcnt, cmp);

            //kruskal
            kruskal();
        }

        if (t) printf("\n");
    }
	return 0;
}
