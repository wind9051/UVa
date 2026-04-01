/*
 * Problem: "UVa 10105 - Polynomial Coefficients"
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學 - 多項式, 排列組合, 階層
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> Fac(20, 0);
void initFactorial() {
    Fac[0] = 1;
    for (int i = 1; i <= 15; i++) {
        Fac[i] = Fac[i-1] * i;
    }
}

int main() {
    initFactorial();
  
    int n, x, k;
    //C(n,k) = n! / (k! * (n-k)!)
    while (cin >> n >> k) {
        ll ans = Fac[n];
        for (int i = 0; i < k; i++) {
            cin >> x;
            ans /= Fac[x];
        }
        printf("%lld\n", ans);
    }
    return 0;
}