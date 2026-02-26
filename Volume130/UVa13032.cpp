/*
 * Problem: "UVa 13032 - Marbles in Jars"
 *  Author: "Jia_coding"
 * 
 *     Tag: 排組（組合）
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main() {
    int T;
    cin >> T;
    for (int Case = 1; Case <= T; Case++) {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        ll ans = 1;
        for (int i = 0; i < n; i++) {
            ll choices = a[i] - i;
            if (choices <= 0) {
                ans = 0;
                break;
            }
            ans = (ans * choices) % MOD;
        }
        printf("Case %d: %lld\n", Case, ans);
    }
    return 0;
}
