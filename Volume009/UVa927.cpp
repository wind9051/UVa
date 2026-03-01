/*
 * Problem: "UVa 927 - Integer Sequences from Addition of Terms"
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學
**/

#include <bits/stdc++.h>
using namespace std;
using LL = long long;


int main () {
    int t;
    cin >> t;
    while (t--) {
        LL N;
        cin >> N;
        vector<LL> a(N+1);
        for (int i = 0; i <= N; i++) {
            cin >> a[i];
        }
        
        LL d, k, cur = 0, n = 0;
        cin >> d >> k;
        while (cur < k) {
            n++;
            cur += n * d;
        }

        LL sum = 0, p = 1;
        for (int i = 0; i <= N; i++) {
            sum += a[i] * p;
            p *= n;
        }
        cout << sum << endl;

    }
    return 0;
}