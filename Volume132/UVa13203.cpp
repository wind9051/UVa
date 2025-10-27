/*
 * Problem: "UVa 13203 - Disk Madness"
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學(math), 數論(number theory), (組合數)
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t n; //long long int
	while (cin >> n) {
		if (n < 3) printf("0\n");
		else printf("%lld\n", (n-2)*(n-1)/2); // C( (n-2), 2)
	}
	return 0;
}
