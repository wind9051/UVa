/*
 * Problem: "UVa 12751 - An Interesting Game"
 *  Author: "Jia_coding"
 * 
 *     Tag: 總和
**/

#include <bits/stdc++.h> 
using namespace std;

int main() {
    int t; 
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int N, k, x;
        cin >> N >> k >> x;
        
        int sum = N * (N+1) / 2;
        int rem = (x + (x+k-1)) * k / 2;
       
        
        printf("Case %d: %d\n", tc, sum - rem);
    }
    return 0;
}
