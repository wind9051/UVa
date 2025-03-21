/*
 * Problem: "UVa 10964 - Strange Planet"
 *  Author: "Jia_coding"
 * 
 *     Tag: coordinate(座標), Math(數學), 等差, 歐幾里得距離
 * 
 *    Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1905
**/

#include <bits/stdc++.h>
using namespace std;

// 4 個方向的位移
int dx[4] = {1, 1, -1, -1};
int dy[4] = {-1, 1, 1, -1};

pair<int, int> getXY(int n) {
    int level = 0, sum = 1;
    while (sum <= n) {
        level++;
        sum += level * 4;
    }
    sum--;

    int x = -level, y = 0; // 0, 4, 12, 24

    // LD, RD, RU, LU
    for (int i = 0; i < 4; i++) {
        if (n >= sum - level) {
            x += (sum - n) * dx[i];
            y += (sum - n) * dy[i];
            return {x, y};
        }
        sum -= level;

        if (i == 0) { // RD
            x = 0;
            y = -level;
        } 
        else if (i == 1) { // RU
            x = level;
            y = 0;
        } 
        else if (i == 2) { // LU
            x = 0;
            y = level;
        } 
    }
    return {x, y}; 
}

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) == 2 && a >= 0) {
        pair<int, int> ap = getXY(a); 
        pair<int, int> bp = getXY(b); 

        int ax = ap.first, ay = ap.second;
        int bx = bp.first, by = bp.second;

        printf("%.2lf\n", hypot(ax - bx, ay - by));
    }
    return 0;
}
