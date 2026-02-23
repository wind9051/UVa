/*
 * Problem: "UVa 201 - Squares"
 *  Author: "Jia_coding"
 * 
 *     Tag: 幾何（矩形）
**/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int x, y;

    bool operator<(const Edge& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

int n, m;
set<Edge> H, V;

bool hasSquare(int i, int j, int l) {
    for (int k = 0; k < l; k++) {
        //UP
        if (!H.count({i, j+k})) return false;
        //Down
        if (!H.count({i+l, j+k})) return false;
        //Left
        if (!V.count({i+k, j})) return false;
        //Right
        if (!V.count({i+k, j+l})) return false;
    }
    return true;
}

int main() {
    int Cas = 1;
    while (cin >> n) {
        cin >> m;
        
        H.clear(); V.clear();
        for (int i = 0; i < m; i++) {
            char d; int u, v;
            cin >> d >> u >> v;
            if (d == 'H') H.insert({u, v});
            if (d == 'V') V.insert({v, u}); //要對調
        }

        if (Cas != 1) printf("\n**********************************\n\n");
        
        printf("Problem #%d\n\n", Cas++);

        bool found = false;
        for (int l = 1; l < n; l++) {
            int cnt = 0;
            for (int i = 1; i + l <= n; i++) {
                for (int j = 1; j + l <= n; j++) {
                    if (hasSquare(i, j, l)) {
                        cnt++;
                    }
                }
            }

            if (cnt) {
                found = true;
                printf("%d square (s) of size %d\n", cnt, l);
            }
        }

        if (!found) printf("No completed squares can be found.\n");
    }
}
