/*
 * Problem: "UVa 1073 - Glenbow Museum"
 *  Author: "Jia_coding"
 * 
 *     Tag: 幾何 - 多邊形, 排組 - 組合
**/

#include <bits/stdc++.h>
using namespace std;

// Combination C(n, k)
long long C(int n, int k) {
    if (k < 0) return 0;
    if (k > n - k) k = n - k; 
    
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int main() {

    int N, Case = 1;
    while (cin >> N && N) {
        int x = (N+4) / 2; // R
        int y = (N-4) / 2; // O
        
        printf("Case %d: ", Case++);
        if (N <= 3 || N & 1) printf("%d\n", 0);
        else printf("%lld\n", C(y + 4, y) + C(y+3, y-1));
    }
    return 0;
}
