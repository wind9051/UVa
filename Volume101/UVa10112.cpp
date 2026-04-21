/*
 * Problem: "UVa 10112 - Myacm Triangles"
 *  Author: "Jia_coding"
 * 
 *     Tag: 幾何 - 三角形 - 向量面積
**/

#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    char ch;
};

int AreaTri(Point a, Point b, Point c) {
    // Triangle Area
    // AB -> (b.x-a.x, b.y-a.y)
    // AC -> (c.x-a.x, c.y-a.y)
    // 0.5 × |(y3 − y1)(x2 − x1) − (y2 − y1)(x3 − x1)|
    return abs((b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x));
}

int main() {
    int n;
    while (cin >> n && n) { 
        vector<Point> p(n); 

        for (int i = 0; i < n; i++) {
            cin >> p[i].ch >> p[i].x >> p[i].y; 
        }
        
        int maxA = 0; 
        string ans = "###"; 
        for (int i = 0; i < n; i++) { //a
            for (int j = i+1; j < n; j++) { //b
                for (int k = j+1; k < n; k++) { //c
                    
                    int area = AreaTri(p[i], p[j], p[k]); 
                    if (area <= maxA) continue; 
                    
                    int flag = 0; 
                    for (int l = 0; l < n && !flag; l++) { //p
                        if (i == l || j == l || k == l) continue; 
                        //Area(ABC) = Area(ABP) + Area(BCP) + Area(CAP)
                        if (AreaTri(p[i], p[j], p[l])+AreaTri(p[j], p[k], p[l])+AreaTri(p[k], p[i], p[l]) == area) {
                           flag = 1;
                        }
                    }
                    if (!flag) { 
                        maxA = area;
                        ans[0] = p[i].ch;
                        ans[1] = p[j].ch;
                        ans[2] = p[k].ch;
                    }
                }
            }
        }
        sort(ans.begin(), ans.end()); 
        cout << ans <<endl; 
    }
    return 0;
}