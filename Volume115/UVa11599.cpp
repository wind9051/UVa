/*
 * Problem: "UVa 11599 - Triangle and Polynomial"
 *  Author: "Jia_coding"
 * 
 *     Tag: 幾何（三角形）　三角函數　多項式
**/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4+5;

int main() {
    int d, n;
    while (cin >> d >> n && d+n != 0) {
        //(8)x^3-(12d)x^2-(18d^2)x+(3d^3)=0
        vector<int> V = {3*d*d*d, -18*d*d, -12*d, 8};
        for (int i = 4; i <= n; i++) {
            V.push_back(0);
            for (int j = i; j > 0; j--) {
                V[j] += V[j-1];
            }
        }
        
        for (int i = n; i >= 0; i--) {
            printf("%d%c", V[i], i != 0 ? ' ' : '\n');
        }
        
    }
    return 0;
}
