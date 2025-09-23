/*
 * Problem: "UVa 1753 - Need for Speed"
 *  GitHub: "https://github.com/wind9051/UVa"
 *  Author: "Jia_coding"
 * 
 *     Tag: BS
**/

#include <bits/stdc++.h>
using namespace std;

struct Section {
    double d, v;
};

int main() {
    int n, t;
    while (cin >> n >> t) {
        vector<Section> Road(n);
        double L = 1e9, R = 1e9; 
        for (int i = 0; i < n; i++) {
            cin >> Road[i].d >> Road[i].v;
            L = min(L, Road[i].v);
        }
        
        L = -L;   // sᵢ + c > 0

        //Binary Search
        while (R - L > 1e-9) {  
            double C = (L + R) / 2.0;
            double sum = 0.0;
            for (int i = 0; i < n; i++) {
                sum += Road[i].d / (Road[i].v + C);
            }
            if (sum > t) L = C;
            else R = C;
        }

        printf("%.9lf\n", (L + R) / 2.0);
    }
    return 0;
}
