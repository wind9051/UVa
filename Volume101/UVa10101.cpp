/*
 * Problem: "UVa 10101 - Bangla Numbers"
 *  Author: "Jia_coding"
 * 
 *     Tag: 遞迴(Recursion)
**/

#include <iostream>
using namespace std;
typedef long long ll;

int num[] = {10000000, 100000, 1000, 100};
string s[] = {"kuti", "lakh", "hajar", "shata"};

void solve(ll n) {
	for (int i = 0; i < 4; i++) {
		if (n >= num[i]) {
			solve(n/num[i]);
			cout << " " << s[i];
			n %= num[i];
		}
	}
	if (n) cout << " " << n;
}

int main () {
	ll n;
	int Case = 1;
	while (cin >> n) {
		printf("%d.", Case++);
		if (n == 0) printf(" 0\n");
		else {
			solve(n);
			printf("\n");
		}
	}
	return 0;
}