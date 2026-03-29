/*
 * Problem: "UVa 13276 - Megamind"
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    int t;
    cin >> t;
    for (int Cs = 1; Cs <= t; Cs++) {
        printf("Case %d: ", Cs);
        
        ll E, P, K, R;
        cin >> E >> P >> K >> R;
        
        // Round 1
        if (E <= P * K) {
            printf("%lld\n", (ll)ceil(E * 1.0 / P));
            continue;
        }
        // Never
        if (P * K <= R) {
            printf("-1\n");
            continue;
        }
        
        // Round X
        ll net = P * K - R;
        ll E_rem = E - P * K;
        ll Round = ceil(E_rem * 1.0 / net);
        ll shoot = Round * K;
        shoot += ceil((E - Round * net) * 1.0 / P);
        
        printf("%lld\n", shoot);
    }
    return 0;
}