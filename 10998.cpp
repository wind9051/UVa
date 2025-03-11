#include<bits/stdc++.h>
using namespace std;

int DFS(double H, double V, double ph, double pv, double x, double y, int c) {
    double hh = H * ph;
    double vv = V * pv;
    
    if (x <= hh && y >= vv) return c; //LU 
    if (x >= hh && y <= vv) return c; //RD 
    
    if (x <= hh) return DFS(H * ph, V * pv, ph, pv, x, y, c^1); //LD
    else return DFS(H * (1-ph), V * (1-pv), ph, pv, x - hh, y - vv, c^1); //RU
}

int main() {
    int Case = 1;
    double H, V, ph, pv, x, y;
    while (cin >> H >> V >> ph >> pv && H) {
        int n;
        cin >> n;
        
        printf("Case %d:\n", Case++);
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            int ans = DFS(H, V, ph, pv, x, y, 1);
            if (ans) printf("black\n");
            else printf("white\n");
        }
    }
    return 0;
}
