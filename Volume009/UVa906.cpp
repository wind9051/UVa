/*
 * Problem: "UVa 906 - Rational Neighbor"
 *  Author: "Jia_coding"
 * 
 *     Tag: 分數　浮點數
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main () {
    LL a, b;
    while (cin >> a >> b) {
        double n;
        cin >> n;
        
        LL d = 1;
        while (true) {
            // ad < bc
            LL c = ceil(a*d / (b*1.0));
            while (a*d >= b*c) c++; //避免精度誤差
            
            
            // c/d - a/b <= n
            if (c*b - a*d <= n*b*d) {
                printf("%ld %ld\n", c, d);
                break;
            }
            
            d++;
        }
    }
}