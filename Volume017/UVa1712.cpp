/*
 * Problem: "UVa 1712 - Cutting Cheese"
 *  Author: "Jia_coding"
 * 
 *     Tag: 幾何（球體）　浮點數
**/

#include <bits/stdc++.h>
using namespace std;
using LD = long double;

const LD PI = acos(-1), EPS = 1e-12;

struct Sphere {
    LD x, y, z, r; // um
}; 

int n, s;

//球體積
LD sphereVolume(LD r) {
    return 4.0 / 3.0 * PI * r * r * r;
}

//球冠體積
LD capVolume(LD r, LD h) {
    return PI * h*h * (3*r - h) / 3.0;
}

LD getblockv(LD l, vector<Sphere> & h) {
    LD res = l * 100 * 100;
    
    for (int i = 0; i < n; i++) {
        //z-r < L < z + r
        if (h[i].z + h[i].r <= l) {
            res -= sphereVolume(h[i].r);
        } 
        else if(h[i].z - h[i].r < l) {
            res -= capVolume(h[i].r, h[i].r - h[i].z + l);
        }
    }
    return res;
}

int main() {
    while (cin >> n >> s) {
        if (n == 0 && s == 0) break;

        vector<Sphere> holes(n); 
        for (int i = 0; i < n; i++) {
            cin >> holes[i].r >> holes[i].x >> holes[i].y >> holes[i].z;
            holes[i].r *= 0.001;
            holes[i].z *= 0.001;
        }

        LD V = 100 * 100 * 100; //um
        for (auto & h : holes) {
            V -= sphereVolume(h.r);
        }

        vector<LD> preV(s+1);
        for (int i = 1; i <= s; i++) {
            LD targetV = V * i / s;

            //BS
            LD L = 0, R = 100, M;
            while (R - L > EPS) {
                M = (L + R) / 2;
                if (getblockv(M, holes) <= targetV) L = M; 
                else R = M;
            }
            preV[i] = L;
        }
        
        for (int i = 1; i <= s; i++) {
            printf("%.10Lf\n", preV[i] - preV[i - 1]);
        }
    }
  	return 0;
}
