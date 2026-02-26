/*
 * Problem: "UVa 13035 - Another Combination Problem"
 *  Author: "Jia_coding"
 * 
 *  Tag: 排列 (Permutation), 數學推導, 模反元素
**/

/* 
 * 排列 P(N,2) = N! / (N-2)! = N × (N-1)
 *
 * 總排列數 Σ_{i=1}^{N} P_{i+1}^2
 *       = Σ_{i=1}^{N} (i+1)i
 *       = Σ i^2 + Σ i
 *       = N(N+1)(2N+1)/6 + N(N+1)/2
 *       = N(N+1)(N+2)/3
 *
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;

ll inv(ll a, ll p) {
    // a^(p-1) == 1 (mod p)
    // a^(p-2) == a^(-1) (mod p)

    // fast_pow
    // a^b mod M
    ll res = 1, b = p-2;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int Case = 1; Case <= T; Case++) {
        ll n;
        cin >> n;

        // X = N(N+1)(N+2)
        ll X = (n * (n+1) % mod) * (n+2) % mod;

        // X = X / 3 (mod M)
        ll inv3 = inv(3, mod);

        printf("Case %d: %lld\n", Case, X * inv3 % mod);
    }

    return 0;
}