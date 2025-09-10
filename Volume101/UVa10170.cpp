/*
 * Problem: "UVa 10170 - The Hotel with Infinite Rooms"
 *  Author: "Jia_coding"
 *
 *     Tag: 數學(Math), 累加(Summation)
 *
**/

#include <iostream>
using namespace std;
typedef long long ll;
int main () {
	ll n, d, sum;
	while (cin >> n >> d) {
		sum = n;
		while (d > sum) sum += ++n;
		printf("%lld\n", n);
	}
	return 0;
}
