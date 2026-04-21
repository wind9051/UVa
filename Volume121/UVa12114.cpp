/*
 * Problem: "UVa 12114 - Bachelor Arithmetic"
 *  Author: "Jia_coding"
 * 
 *     Tag: 機率, 分數
**/

#include <bits/stdc++.h>
using namespace std;

double f(int s, int b) { 
    if (s >= b) return 1;
    else return 1.0 * s / b; 
}

int main() {
    int B, S;
    int Case = 1;
    while (cin >> B >> S && B+S != 0) { 
        printf("Case %d: ", Case++);
        if (B == 1) printf(":-\\\n");
        else if (f(S, B) <  f(S-1, B-1)) printf(":-)\n");
        else if (f(S, B) == f(S-1, B-1)) printf(":-|\n");
        else if (f(S, B) >  f(S-1, B-1)) printf(":-(\n");
    }
    return 0;
}
