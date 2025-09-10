/*
 * Problem: "UVa 10110 - Light, more light"
 *  Author: "Jia_coding"
 *
 *     Tag: 數學(Math), 平方數(Perfect Square)
 *          
 *
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main () {
    ll n;
    while (cin >> n && n) {
        ll x = sqrt(n);
        if (x*x == n) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}