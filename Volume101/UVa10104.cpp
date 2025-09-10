/*
 * Problem: "UVa 10104 - Euclid Problem"
 *  Author: "Jia_coding"
 *
 *     Tag: 數學(Math), 最大公因數(GCD), 擴展歐幾里得(Extended Euclidean Algorithm), 
 *          
 *
**/

#include <iostream>
using namespace std;
typedef long long ll; 
 
ll ex_gcd(ll a, ll b, ll & x, ll & y){
    if (b == 0) {
        x = 1; y = 0;
        return a;
    } 
    else {
        ll x1, y1;
        ll d = ex_gcd(b, a % b, x1, y1);

        x = y1;
        y = x1 - (a/b) * y1;
        
        return d;
    }
}
 
int main() {
    ll a, b, x, y;
    while (cin >> a >> b){
        ll d = ex_gcd(a, b, x, y);
        printf("%lld %lld %lld\n", x, y, d);
    }
    return 0;
}

/*
    gcd(a, b)   = ax + by
    gcd(b, a%b) = bx1 + (a-(a/b)*b)y1
    
    ay1+b(x1-(a/b)y1) = ax + by
    
    x = y1
    y = x1 - (a/b)y1
*/