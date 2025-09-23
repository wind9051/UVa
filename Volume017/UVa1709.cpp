/*
 * Problem: "UVa 1709 - Amalgamated Artichokes"
 *  GitHub: "https://github.com/wind9051/UVa"
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學 - 股價, 最大差值 
**/

#include <bits/stdc++.h>
using namespace std;

int main () {
    double p, a, b, c, d, n;
    while (cin >> p >> a >> b >> c >> d >> n) {
        double maxP = -1e9, maxDif = -1e9;
        vector<double> P(n+1, 0);
        for (int i = 1; i <= n; i++) {
            //P[k] = p * (sin(ak+b) + cos(ck+d) + 2)
            P[i] = p*(sin(a*i+b) + cos(c*i+d) + 2);
            maxP = max(P[i], maxP);
            maxDif = max(maxP - P[i], maxDif);
        }
        printf("%.6f\n", maxDif);
    }
    return 0;
}