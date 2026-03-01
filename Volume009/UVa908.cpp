/*
 * Problem: "UVa 908 - Re-connecting Computer Sites"
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖論(Graph), 最大生成樹(MST), 克魯斯克爾演算法(Kruskal's Algorithm)
**/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<int> root, sz;

int find_root(int x) {
    if (root[x] == x) return x;
    return root[x] = find_root(root[x]);
}

bool unite(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) return false;

    if (sz[a] < sz[b]) swap(a, b);
    root[b] = a;
    sz[a] += sz[b];
    return true;
}

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());

    
    root.resize(n+1), sz.resize(n+1);
    for (int i = 1; i <= n; i++) {
        root[i] = i, sz[i] = 1;
    }

    int total = 0;
    for (auto& e : edges) {
        if (unite(e.u, e.v)) {
            total += e.w;
        }
    }
    return total;
}

int main() {
    int n, Case = 0;
    while (cin >> n) {
        if (Case) cout << "\n";
        
        int oldCost = 0;
        for (int i = 0; i < n-1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            oldCost += w;
        }
        cout << oldCost << "\n";

        
        vector<Edge> edges;

        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            Edge e;
            cin >> e.u >> e.v >> e.w;
            edges.push_back(e);
        }
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            Edge e;
            cin >> e.u >> e.v >> e.w;
            edges.push_back(e);
        }

        cout << kruskal(n, edges) << "\n";
    }
    return 0;
}