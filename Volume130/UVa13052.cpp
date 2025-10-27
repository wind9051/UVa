/*
 * Problem: "UVa 13052 - Fisa Flood"
 *  Author: "Jia_coding"
 * 
 *     Tag: 模擬, 貪心
**/

#include <bits/stdc++.h>
using namespace std;

int main () {
    int t, Case = 1;
    cin >> t;
    while (t--) {
        int A, B;
        cin >> A >> B;
        
        //two Fisaloca(B) -> one Fisadasa(A)
        A += B / 2;
        B = B % 2;
        
        //two Fisadasa(A) -> one Fisadasa(A)
        while (A > 1) {
            A = A / 2 + A % 2;
        }
        
        printf("Case %d: ", Case++);
        if (A == 0 && B == 0) printf("0.000 0.000\n");
        else if (B != 0) printf("0.000 1.000\n");
        else printf("1.000 0.000\n");
    }
    return 0;
}