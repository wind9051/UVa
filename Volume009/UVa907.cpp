/*
 * Problem: "UVa 907 - Winterim Backpacking Trip"
 *  Author: "Jia_coding"
 * 
 *     Tag: BS(二分搜)
**/

#include <bits/stdc++.h>
using namespace std;

int n, k;
bool canPath(int L, vector<int> & N) {
    int sum = 0, stay = 0;
    for (int i = 0; i < n+1; i++) {
        if (N[i] > L) return 0;
        if (sum + N[i] > L) {
            stay ++;
            sum = N[i];
        }
        else {
            sum += N[i];
        }
    }
    return stay <= k;
} 

int main () {
    while (cin >> n >> k) {
        int sum = 0;
        vector<int> N(n+1);
        for (int i = 0; i < n+1; i++) {
            cin >> N[i];
            sum += N[i];
        }

        //BS
        int L = 0, R = sum;
        while (L < R) {
            int M = L + (R-L) / 2;
            if (canPath(M, N)) {
                R = M;
            }
            else {
                L = M+1;
            }
        }
        cout << L << endl;
    }
    return 0;
}