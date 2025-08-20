/*
 * Title:  "UVa 10018 - Reverse and Add"
 * Author: "Jia_coding"
 *   
 *    tag: 回文(Palindrome)
**/

#include <iostream>
using namespace std;
typedef long long ll;

ll rev(ll n) {
	ll num = 0;
	while (n) {
		num = num * 10 + n % 10;
		n /= 10;
	}
	return num;
}

int main () {
	int t; 
	cin >> t;
	while (t--) {
		ll n; 
		cin >> n;
		ll a = n, b = rev(a);
		
		int cnt = 0;
		while (a != b) {
			a = a + b;
        	b = rev(a);
			cnt++;
		}
		cout << cnt << " " << a << endl;
	}
	return 0;
}