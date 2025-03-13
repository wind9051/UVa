/*
  ID: 10099 
  Name: The Tourist Guide
  Author: Jia-Cheng Yao
  
  Key: 路徑, 圖, Kruskal, 生成樹
*/



#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w > b.w;
}

vector<int> root(105, 0);
int find_root(int x) {
    if (root[x] == x) return x;
    return root[x] = find_root(root[x]);
}

int main () {
    int V, R, Case = 1;
    while (cin >> V >> R && V && R) {
        
        Edge E[R];
        for (int i = 0; i < 100; i++) root[i] = i;
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
        
        for (int i = 0; i < R; i++) {
            int x = find_root(E[i].u);
            int y = find_root(E[i].v);
            if (x != y) {
                root[x] = y;
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
