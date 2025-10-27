/*
 * Problem: "UVa 10397 - Connect the Campus"
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖論(Graph), 最小生成樹(MST), 克魯斯克爾演算法(Kruskal's Algorithm), 歐幾里得距離（Euclidean Distance）
**/

#include <bits/stdc++.h>
using namespace std;

double sum;
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

bool Union(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    if (x != y) {
        if (Rank[x] > Rank[y]) {
            Rank[x] += Rank[y];
            root[y] = x;
        }
        else {
            Rank[y] += Rank[x];
            root[x] = y;
        }
        return true;
    }
    return false;
}

void kruskal() {
    sum = 0.0;
    treecnt = 0;
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
    while (cin >> N) {
		init();

        for (int i = 1; i <= N; i++) {
            cin >> P[i].x >> P[i].y;
        }
		
        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> E[i].u >> E[i].v;
            Union(E[i].u, E[i].v);
        }
    
		idcnt = 0;
		for (int i = 1; i <= N-1; i++) {
			for (int j = i + 1; j <= N; j++) {
				E[idcnt].u = i;
				E[idcnt].v = j;
				E[idcnt++].w = dist(P[i].x, P[j].x, P[i].y, P[j].y);
			}
		}
		sort(E, E+idcnt, cmp);
		
		kruskal();
		
    }
	return 0;
}
