/*
 * Title:  "UVa10104 - Euclid Problem"
 * Author: "Jia_coding"
 * Date:   "2024/08/16"
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void exEuclidean(ll a, ll b, ll &x, ll &y, ll &d) {
    
    if (!b) {
        d = a, x = 1, y = 0;
    }
    else {
        exEuclidean(b, a%b, y, x, d);
        y -= x * (a/b);
    }
}

int main () {
    ll a, b, x, y, d;
    while (cin >> a >> b) {
        exEuclidean(a, b, x, y, d);
        cout << x << " " << y << " " << d << endl;
    }
    return 0;
}
