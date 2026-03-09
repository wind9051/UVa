/*
 * Problem: "UVa 1001 - Say Cheese"
 *  Author: "Jia_coding"
 * 
 *     Tag: Floyd　幾何（圓）
**/

#include<bits/stdc++.h>
using namespace std;

struct Circle{
    int x, y, z, r;

    Circle() {}
};

double dist(Circle &A, Circle &B) {
    double d = sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y) + (A.z - B.z)*(A.z - B.z));
    if (d <= (A.r + B.r)) return 0; //相交, 相切
    return d - A.r - B.r;
}
 
int main() {
    int n, Cas = 1;
    while (cin >> n && n != -1) {
        vector<Circle> C(n+2);
        for (int i = 1; i <= n; i++) {
            cin >> C[i].x >> C[i].y >> C[i].z >> C[i].r;
        }

        cin >> C[0].x >> C[0].y >> C[0].z; C[0].r = 0;
        cin >> C[n+1].x >> C[n+1].y >> C[n+1].z; C[n+1].r = 0;
        
        vector<vector<double>> DP(n+2, vector<double>(n+2));        
        for (int i = 0; i <= n + 1; i ++) {
            for (int j = i + 1; j <= n + 1; j ++) {
                DP[i][j] = DP[j][i] = dist(C[i], C[j]);
            }
        }

        //Floyd
        for (int k = 0; k <= n+1; k++) {
            for (int i = 0; i <= n+1; i++) {
                for (int j = 0; j <= n+1; j++) {
                    DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
                }
            }
        }
        
        printf("Cheese %d: Travel time = %.0f sec\n", Cas++, round(DP[0][n+1]*10));
    }
    return 0;
}
