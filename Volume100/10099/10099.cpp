/*
 * Problem: "UVa 10099 - The Tourist Guide"
 *  Author: "Jia_coding"
 *    Date: "2025/03/13"
 *     Tag: Kruskal, MST, Graph
 *          生成树, 圖
 */

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w > b.w;
}

vector<int> Root(105, 0);
int find_root(int x) {
    if (Root[x] == x) return x;
    return Root[x] = find_root(Root[x]);
}

int main () {
    int V, R, Case = 1;
    while (cin >> V >> R && V && R) {
        
        Edge E[R];
        for (int i = 0; i < 100; i++) Root[i] = i;
        for (int i = 0; i < R; i++) {
            cin >> E[i].u >> E[i].v >> E[i].w;
        }
        sort(E, E+R, cmp);
        /*
        for (int i = 0; i < R; i++) {
            cout << E[i].u <<" "<<E[i].v<<" "<< E[i].w<<endl;
        }
        */
        
        int s, e, sum, ans = 0;
        cin >> s >> e >> sum;
        
        //kruskal
        for (int i = 0; i < R; i++) {
            int a = find_root(E[i].u);
            int b = find_root(E[i].v);
            if (a != b) {
                Root[a] = b;
            }
            if (find_root(s) == find_root(e)) {
                ans = E[i].w;
                break;
            }
        }
        //cout<<sum<<" "<<ans<<endl;
        int now = sum % (ans-1) != 0 ? 1 : 0;
        
        printf("Scenario #%d\n", Case++);
        printf("Minimum Number of Trips = %d\n\n", sum / (ans-1) + now);
    }
    return 0;
}