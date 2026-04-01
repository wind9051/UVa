/*
 * Problem: "UVa 10147 - Highways"
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖論(Graph), 最小生成樹(MST), 克魯斯克爾演算法(Kruskal's Algorithm), 歐幾里得距離（Euclidean Distance）
**/

#include <bits/stdc++.h>
using namespace std;

int N, M, idcnt, treecnt;
int root[5005], rnk[5005];

struct Point {
    int x, y;
} P[755];

struct Edge {
    int u, v; 
    double w;

    bool operator< (const Edge & other) const {
        return w < other.w;
    }
};

int find_root(int x) {
    if (root[x] == x) return x;
    return root[x] = find_root(root[x]);
}


double dist(Point &a, Point &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

void UNION(int a, int b) {
    int x = find_root(a);
    int y = find_root(b);
    if (x == y) return;

    if (rnk[x] < rnk[y]) swap(x, y);

    root[y] = x;
    rnk[x] += rnk[y];
}

int main() {
	int t;
    cin >> t;
    while (t--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> P[i].x >> P[i].y;

            //init()
            root[i] = i, rnk[i] = 1; 
        }

        cin >> M;
        
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            UNION(u, v);
        }

        vector<Edge> edges;
        for (int i = 1; i <= N-1; i++) {
            for (int j = i + 1; j <= N; j++) {
                edges.push_back({i, j, dist(P[i], P[j])});
            }
        }
        sort(edges.begin(), edges.end());

        //kruskal
        vector<Edge> ans;
        for (auto &e : edges) {
            if (find_root(e.u) != find_root(e.v)) {
                UNION(e.u, e.v);
                ans.push_back({e.u, e.v});
            }
        }

        if (ans.empty()) {
            cout << "No new highways need\n";
        } 
        else {
            for (auto &p : ans) {
                cout << p.u << " " << p.v << "\n";
            }
        }

        if (t) printf("\n");
    }
	return 0;
}
