/*
 * Problem: "UVa 12799 - RSA"
 *  Author: "Jia_coding"
 * 
 *     Tag: 質數（歐拉）　模數（逆反）　快速冪　exGCD　　
**/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod_pow(ll a, ll e, ll mod) {
    ll r = 1;

    a %= mod;
    while (e > 0) {
        // __int128
        if (e & 1) r = (ll)((ll)r * a % mod);

        a = (ll)((ll)a * a % mod);

        e >>= 1;
    }
    return r;
}

ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll g = ex_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return g;
}

ll mod_inv(ll e, ll phi) {
    
    // d ≡ E^{-1} mod φ(N)
    // Ex + φ(N)y = 1  (x = d)
    ll x, y;
    ex_gcd(e, phi, x, y);

    return (x % phi + phi) % phi;
}

int main() {

    ll N, E, C;
    while (cin >> N >> E >> C) {

        // N = p * q
        ll p, q;
        for (ll i = 3; i * i <= N; i++) {
            if (N % i == 0) {
                p = i;
                q = N / i;
                // break;
            }
        }

        // φ(N) = (p-1)(q-1)
        ll phi = (p - 1) * (q - 1);

        // d ≡ E^{-1} mod φ(N)
        ll d = mod_inv(E, phi);

        // M = C^d mod N
        ll M = mod_pow(C, d, N);

        cout << M << "\n";
    }
    return 0;
}