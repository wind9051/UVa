// UVa 13302 - Jawbreaking Candy
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

pll fac(ll a, ll b) {
    ll g = __gcd<ll>(a, b);
    a /= g;
    b /= g;

    return {a, b};
}

bool is_less(pll &a, pll &b) {
    return a.first * b.second < b.first * a.second;
}

int main () {
    ll L, n, d;
    while (cin >> L >> n >> d && L && n && d) {
        pll p = {0, 0}, tmp;
        for (int i = 1; i < n+1; i++) {
            ll a = (d*i + L-1) / L;  // a/b

            tmp = fac(a*L, i);

            if (p.first == 0) p = tmp;
            else if (is_less(tmp, p)) p = tmp;
        }
        printf("%lld/%lld\n", p.first, p.second);
    }
    return 0;
}
