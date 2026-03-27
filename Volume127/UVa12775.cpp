/*
 * Problem: "UVa 12775 - Gift Dilemma"
 *  Author: "Jia_coding"
 * 
 *     Tag: ExGCD
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1; 
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = ex_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        ll A, B, C, P;
        cin >> A >> B >> C >> P;

        ll ans = 0;

        // Ax + By + Cc = P
        // Ax + By = P - Cc
        for (ll c = 0; c * C <= P; c++) {
            ll rem = P - c * C;

            ll x, y;
            // Ax + By = gcd(A,B)
            ll g = ex_gcd(A, B, x, y);

            // printf("gcd equation: %lld*%lld + %lld*%lld = %lld\n", A, x, B, y, g);

            if (rem % g != 0) continue;

            // A x + B y = g
            // A (x*k) + B (y*k) = rem   (k = rem/g)
            x *= rem / g;
            y *= rem / g;

            // printf("particular solution: %lld*%lld + %lld*%lld = %lld\n", A, x, B, y, rem);

            // x = x0 + (B/g) t
            // y = y0 - (A/g) t
            
            ll dx = B / g;
            ll dy = A / g;

            // x = x0 + dx * t >= 0
            // t >= -x0 / dx
            ll t1 = (ll)ceil((double)(-x) / dx);

            // y = y0 - dy * t >= 0
            // t <= y0 / dy
            ll t2 = (ll)floor((double)(y) / dy);

            // t1 < t < t2

            if (t1 <= t2) {
                ans += (t2 - t1 + 1LL);
            }
        }

        cout << "Case " << tc << ": " << ans << "\n";
    }

    return 0;
}