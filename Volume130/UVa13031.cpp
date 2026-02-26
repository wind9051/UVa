/*
 * Problem: "UVa 13031 - Geek Power Inc."
 *  Author: "Jia_coding"
 * 
 *     Tag: 哈希
**/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    for (int Cas = 1; Cas <= t; Cas++) {
        ll n, cnt = 0;
        cin >> n;
        
        map<ll, ll> Hash;
        for (int i = 0; i < n; i++) {
            ll r, c;
            cin >> r >> c;
            Hash[c] += r;
            cnt += r;
        }
        ll ans = 0;
        for (auto [u, v] : Hash) {
            ans = max(ans, u * cnt);
            cnt -= v;
        }
        printf("Case %d: %lld\n", Cas, ans);
    }
    return 0;
}
