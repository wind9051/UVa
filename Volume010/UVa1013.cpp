/*
 * Problem: "UVa 1013 - Island Hopping"
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖論(Graph), 最小生成樹(MST) - Kruskal, 歐幾里得距離（Euclidean Distance） Floyd
**/

#include <bits/stdc++.h>
using namespace std;


int N;
int root[5005], Rank[5005];

struct Point {
    int x, y, w;
};

struct Edge {
    int u, v; 
    double d;

    bool operator< (const Edge & other) {
        return d < other.d;
    }
};

void init() {
    for(int i = 0; i <= N; i++) {
        root[i] = i, Rank[i] = 1; 
    }
}

int find_root(int x) {
    if (root[x] == x) return x;
    return root[x] = find_root(root[x]);
}

double dist_Euclidean(Point & A, Point & B) {
    int dx = B.x - A.x, dy = B.y - A.y;
    return sqrt(dx*dx + dy*dy);
}

vector<vector<double>> kruskal(vector<Edge> & E) {
    vector<vector<double>> G(N+1, vector<double>(N+1, 1e9));
    for (int i = 1; i <= N; i++) G[i][i] = 0.0;
    
    for (int i = 0; i < E.size(); i++) {
        int x = find_root(E[i].u);
        int y = find_root(E[i].v);
        if (x != y) {
            // x 大集合
            if (Rank[x] < Rank[y]) swap(x, y);
            
            Rank[x] += Rank[y];
            root[y] = x;
            
            G[E[i].u][E[i].v] = G[E[i].v][E[i].u] = E[i].d;
        }
        
    }
    return G;
}

int main() {
    int Cas = 1;
    while (cin >> N && N) {
        init();

        vector<Point> P(N+1);
        for (int i = 1; i <= N; i++) {
            cin >> P[i].x >> P[i].y >> P[i].w;
        }

        //Edge
        vector<Edge> E;
        for (int i = 1; i <= N-1; i++) {
            for (int j = i + 1; j <= N; j++) {
                Edge Cur;
                Cur.u = i;
                Cur.v = j;
                Cur.d = dist_Euclidean(P[i], P[j]);
                E.push_back(Cur);
            }
        }
        sort(E.begin(), E.end());

        //kruskal
        vector<vector<double>> DP = kruskal(E);
    
        //Floyd
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    DP[i][j] = min(DP[i][j], max(DP[i][k], DP[k][j]));
                }
            }
        }
        
        double sum = 0.0, m = 0.0;
        for (int j = 1; j <= N; j++) {
            sum += P[j].w * DP[1][j];
            m += P[j].w;
        }
        printf("Island Group: %d Average %.2lf\n\n", Cas++, sum / m);
    }
	return 0;
}
