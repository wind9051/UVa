/*
 * UVa 10002 - Center of Masses
 */

#include <bits/stdc++.h>
using namespace std;

// 定義點的資料結構，包括 x 和 y 座標，以及到參考點的距離 d
struct point {
    double x, y, d;
};

point P[105];  // 原始點的陣列
point S[105];  // 凸包的點的陣列
point MP;      // 凸包中的一個參考點

// 計算兩點之間的歐幾里德距離
double dist(point a, point b) {
    return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}

// 計算三個點的叉積
double crossproduct(point a, point b, point c) {
    return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

// 自定義比較函數，用於排序點，首先根據 x 座標排序，如果 x 相等，則根據 y 座標排序
bool cmp(point a, point b) {
    if (a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}

// 自定義比較函數，用於計算點的排序，以確保它們在凸包上以逆時針方向排列
bool cmp_cross(point b, point c) {
    return crossproduct(P[0], b, c) > 0;
}

// 自定義比較函數，用於排序點，用於處理共線情況，確保按照適當的順序排序
bool cmp_MP(point b, point c) {
    double cp = crossproduct(P[0], b, c);
    if (cp == 0.0) {
        if (!crossproduct(P[0], b, MP)) return b.d < c.d;
        else return b.d > c.d;
    }
    else return cp > 0;
}

// 計算一組點的重心
point center(point * Point, int n) {
    double sum = 0.0;
    point ans; ans.x = ans.y = 0.0;
    
    for (int i = 2; i < n; i++) {
        double s = crossproduct(Point[0], Point[i-1], Point[i]);
        ans.x += (Point[0].x + Point[i-1].x + Point[i].x) * s;
        ans.y += (Point[0].y + Point[i-1].y + Point[i].y) * s;
        sum += s;
    }
    ans.x /= 3 * sum;
    ans.y /= 3 * sum;
    return ans;
}

// Graham's Scan 凸包算法
void Graham(int n) {
    // 按照 x 座標排序
    sort(P, P + n, cmp);
    
    // 按照逆時針方向排序
    sort(P + 1, P + n, cmp_cross);
    
    // 處理共線情況，並計算距離到參考點的距離
    for (int i = 1; i < n; i++) {
        P[i].d = dist(P[0], P[i]);
    }
    MP = P[n-1];
    sort(P + 1, P + n, cmp_MP);
    
    // Graham's Scan 算法找到凸包
    int top = -1;
    if (n > 0) S[++top] = P[0];
    if (n > 1) S[++top] = P[1];
    if (n > 2) {
        S[++top] = P[2];
        for (int i = 3; i < n; i++) {
            while (crossproduct(S[top-1], S[top], P[i]) < 0) --top;
            S[++top] = P[i];
        }
    }
    S[++top] = P[0];
    
    // 計算凸包的重心
    point c = center(S, top);
    
    printf("%.3lf %.3lf\n", c.x, c.y);
}

int main() {
    int n;
    while (cin >> n && n > 2) {
        for (int i = 0; i < n; i++) {
            cin >> P[i].x >> P[i].y;
        }
        Graham(n);
    }
    return 0;
}
