/*
 * Problem: "UVa 10125 - Sumsets"
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學(A+B+C=D), Two pointer
**/

#include <bits/stdc++.h>
using namespace std;

const int inf = -1e9;  

int main() {
    int n;
    while (cin >> n && n) {
        vector<int> N(1005, 0);
        for (int i = 0; i < n; i++) {
            cin >> N[i];
        }
        sort(N.begin(), N.begin() + n); 

        int ans = inf;

        for (int D = n-1; D >= 0; D--) {
            for (int C = n-1; C >= 0; C--) {
                if (D == C) continue;   
                
                // D-C
                int sum = N[D] - N[C];  

                //BS二分搜 A + B
                int L = 0, R = C-1;
                while (L < R) {
                    if (N[L] + N[R] == sum) {
                        ans = N[D];
                    } 
                    
                    if (N[L] + N[R] > sum) R--;
                    else L++;
                }
                if (ans != inf) break;  
            }
            if (ans != inf) break;      
        }
        
        if (ans == inf) printf("no solution\n");
        else printf("%d\n", ans);
    }
    return 0;
}
