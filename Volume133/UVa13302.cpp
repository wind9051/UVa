/*
 * Problem: "UVa 13302 - Jawbreaking Candy"
 *  Author: "Jia_coding"
 * 
 *     Tag: math(數學), 分數, GCD 
 * 
**/

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

vector<LL> sim_fra(LL a, LL b) {
    LL g = __gcd(a, b);
    a /= g;
    b /= g;
    return {a, b};
}

// x = (a, b), y = (c, d)
// a/b > c/d ->  ad > cb
bool is_greater(vector<LL> &x, vector<LL> &y) {
    return x[0] * y[1] > y[0] * x[1];
}

int main () {
    LL L, n, d;
    while (cin >> L >> n >> d && L && n && d) {
        vector<LL> ans = {LLONG_MAX, 1};
        for (int b = 1; b <= n; b++) {
            // a/b > d, b = [1~n]
            // a > bd, a = ml
            
            LL m = (b * d + L-1) / L; 
            // ll m = (ll)ceil((b * d) / L);

            vector<LL> tmp = sim_fra(m * L, b);
            if(is_greater(ans, tmp)) ans = tmp;
        }
        printf("%lld/%lld\n", ans[0], ans[1]);
    }
    return 0;
}
