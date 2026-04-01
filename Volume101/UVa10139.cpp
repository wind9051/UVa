/*
 * Problem: "UVa 10139 - Factovisors"
 *  Author: "Jia_coding"
 * 
 *     Tag: 階層 因數
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    while (cin >> n >> m) {
        // M = p1^k1 * p2^k2 ... pn^kn
        map<ll, int> prime;

        ll cur = m;
        for (ll p = 2; p*p <= cur; p++) {
            if (cur % p == 0) {
                while (cur % p == 0) {
                    cur /= p;
                    prime[p]++;
                }
            }
        }
        if (cur > 1) {
            prime[cur]++;
        }

        bool flag = 0;
        for (auto [k, v] : prime) {
            // printf("m : %d^%d\n", k, v);

            ll cnt = 0, den = k;
            while (den <= n) {
                cnt += n / den;
                den *= k;
            }
            
            if (cnt < v) {
                flag = 1;
                break;
            }
        }
        if (flag) printf("%lld does not divide %lld!\n", m, n);
        else printf("%lld divides %lld!\n", m, n);
    }
	return 0;
}
