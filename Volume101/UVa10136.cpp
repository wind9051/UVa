/*
 * Problem: "UVa 10136 - Chocolate Chip Cookies"
 *  Author: "Jia_coding"
 *
 *     Tag: 幾何 - 圓, 歐幾里得距離, , 最大覆蓋問題      
 *
**/

#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

struct Point {
    double x, y;
};

double dist_Euclidean(Point & A, Point & B) {
    return sqrt((B.x-A.x) * (B.x-A.x) + (B.y-A.y) * (B.y-A.y));
}

int main () {
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while (t--) {
        string S;
        int cnt = 0;
        vector<Point> P(205);
        while (getline(cin, S) && S.size()) {
            stringstream ss(S);
            ss >> P[cnt].x >> P[cnt++].y;
        }
        
        int maxn = 0;
        for (int i = 0; i < cnt; i++) {
            for (int j = i; j < cnt; j++) {
                Point C;
                C.x = (P[i].x + P[j].x) / 2;
                C.y = (P[i].y + P[j].y) / 2;
                int now = 0;
                for (int k = 0; k < cnt; k++) {
                    double d = dist_Euclidean(C, P[k]);
                    if (d <= (2.5+eps)) now++;
                }
                maxn = max(now, maxn);
            }
        }
        cout << maxn << endl;
        
        if (t) cout << endl;
    }
    return 0;
}