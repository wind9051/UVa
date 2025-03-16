/*
 * Problem: "UVa 10504 - Hidden squares"
 *  Author: "Jia_coding"
 *    Date: "2025/03/14"
 *     Tag: Geometry, Coordinates, Vector Rotation 
 *          幾何, 矩形, 座標, 向量旋轉 
**/

#include <bits/stdc++.h>
using namespace std;

struct Pt {
    int x, y;
    
    Pt(int a=0, int b=0) : x(a), y(b) {}
    bool operator<(const Pt &a) const {
        if(x != a.x) return x < a.x;
        return y < a.y;
    }
};

bool cmp (const Pt & a, const Pt & b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int cntSquare(vector<Pt> & P, int n) {
    sort(begin(P), begin(P)+n, cmp);

    set<Pt> S;
    for (int i = 0; i < n; i++) {
        S.insert(P[i]);
    }
    
    int x, y, ret = 0;
    // "Iterate all possible point pairs (P[i], P[j])".
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            //固定P[i], P[j]順轉90度
            //x' = x - (y - y0)
            //y' = y + (x - x0)
            int dx = P[j].x - P[i].x; 
            int dy = P[j].y - P[i].y; 
            x = P[i].x - dy;
            y = P[i].y + dx;
            if (x < 0 || x >= 105 || y < 0 || y >= 105) continue;
            if (S.find(Pt(x, y)) == S.end()) continue;
            //固定P[j], P[i]逆轉90度
            //x' = x - (y - y0)
            //y' = y + (x - x0)
            x = P[j].x - dy;
            y = P[j].y + dx;
            if (x < 0 || x >= 105 || y < 0 || y >= 105) continue;
            if (S.find(Pt(x, y)) == S.end()) continue;

            //x - dy >= 0 
            if (dy > 0) continue;
            
            ret++;
        }
    }
    return ret;
}
int main() {
    int Case = 0;
    int n, m;
    vector<Pt> P(10005);
    vector<vector<char>> G(105, vector<char>(105));
    while (cin >> n && n) {
        cin >> m;
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < n; j++) {
                G[i][j] = s[j];
            }
        }
        if (Case++) printf("\n");
        while (m--) {
            char c;
            cin >> c;
            int pcnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (G[i][j] == c) {
                        P[pcnt].x = i;
                        P[pcnt].y = j;
                        pcnt++;
                    }
                }
            }
            printf("%c %d\n", c, cntSquare(P, pcnt));
        }
    }
    return 0;
}