/*
 * Problem: "UVa 13302 - Jawbreaking Candy"
 *  Author: "Jia_coding"
 * 
 *     Tag: math(數學), 分數, GCD 
 * 
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

pll sim_fra(ll a, ll b) {
    ll g = __gcd(a, b);
    a /= g;
    b /= g;
    return {a, b};
}

//ax / bx > ay / by
bool is_less(pll &x, pll &y) {
    return x.first * y.second > y.first * x.second;
}

int main () {
    ll L, n, d;
    while (cin >> L >> n >> d && L && n && d) {
        pll ans = {};
        for (int b = 1; b <= n; b++) {
            /* a/b > d, b = [1~n]
               a > bd, a = ml
            */
            ll m = (b * d + L-1) / L; 
            
            pll tmp;
            tmp = sim_fra(m * L, b);
            if (b == 1) ans = tmp;
            else if (is_less(ans, tmp)) ans = tmp;
        }
        printf("%lld/%lld\n", ans.first, ans.second);
    }
    return 0;
}
