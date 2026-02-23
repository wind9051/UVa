/*
 * Problem: "UVa 231 - Testing the CATCHER"
 *  Author: "Jia_coding"
 * 
 *     Tag: DP(LIS)
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, Case = 0;
    while (cin >> x && x != -1){
        vector<int> a;
        a.push_back(x);
        while (cin >> x && x != -1) a.push_back(x);


        //LIS
        int maxn = 1;
        vector<int> DP(a.size(), 1);
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] <= a[j] && DP[j]+1 > DP[i]){
                    DP[i] = DP[j]+1;
                    maxn = max(maxn, DP[i]);
                }
            }
        }

        if (Case) printf("\n");
        printf("Test #%d:\n  maximum possible interceptions: %d\n", ++Case, maxn);
    }
}
