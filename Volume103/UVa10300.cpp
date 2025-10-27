/*
 * Title:  "UVa 10300 - Ecological Premium"
 * Author: "Jia_coding"
 *   
 *    tag: 數學(Math))
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t;
	cin >> t;
    while (t--) {
    	int f;
		cin >> f;
		ll money = 0;
    	while (f--) {
    		ll a, n, l; //area number level 
    		cin >> a >> n >> l;
    		money += a * l;
		}
		cout << money << endl;
	}
    return 0;
}
//money = ((a/n)*l)*n = a *l