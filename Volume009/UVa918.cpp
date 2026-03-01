/*
 * Problem: "UVa 918 - ASCII Mandelbrot"
 *  Author: "Jia_coding"
 * 
 *     Tag: 複數 浮點數
**/

#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        double minI, maxI, pI, minR, maxR, pR;
        cin >> s >> minI >> maxI >> pI >> minR >> maxR >> pR;
        s[13] = ' ';
        for (double i = minI; i <= maxI + EPS; i += pI) {
            for (double j = minR; j <= maxR + EPS; j += pR) {
                /*
                    z = a + bi
                    f(z) = z^2 + C
                         = (a+bi)^2 + C
                         = a^2 + 2abi - b^2i^2 + C
                */
                int c;
                float a = 0, b = 0;
                for (c = 1; c <= 12; c++) {
                    float ta = a*a - b*b;
                    float tb = 2*a*b;
                    
                    a = ta + j;
                    b = tb + i;
                    if (a*a + b*b > 4.0) {
                        break;
                    }
                }
                cout << s[c];
            }
            cout << endl;
        }
        if (t) cout << endl;
    }
    return 0;
}