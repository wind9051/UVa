/*
 * Problem: "UVa 914 - Jumping Champion"
 *  Author: "Jia_coding"
 * 
 *     Tag: 質數(埃式篩)
**/

#include <bits/stdc++.h>
using namespace std;

vector<int> sieve_eratosthenes(int MAXN) {
    vector<bool> isPrime(MAXN + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    vector<int> Prime;
    for (int i = 2; i <= MAXN; i++) {
        if (isPrime[i]) Prime.push_back(i);
    }
    return Prime;
}


int main () {
    vector<int> Prime = sieve_eratosthenes(1e6);

    int t;
    cin >> t;
    while (t--) {
        int L, U;
        cin >> L >> U;
        
        int maxn = 0, ans = -1;
        unordered_map<int, int> cnt;
        auto it = lower_bound(Prime.begin(), Prime.end(), L);
        for (int i = it - Prime.begin(); i+1 < Prime.size() && Prime[i+1] <= U; i++) {
            int diff = Prime[i+1] - Prime[i];
            int curCnt = ++cnt[diff];
            if (curCnt > maxn) {
                maxn = curCnt;
                ans = diff;
            }
            else if (curCnt == maxn) {
                ans = -1;
            }
        }
        if (ans == -1) printf("No jumping champion\n");
        else printf("The jumping champion is %d\n", ans);
    }
    return 0;
}