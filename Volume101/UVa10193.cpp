/*
 * Problem: "UVa 10193 - All You Need Is Love"
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學(Math), 最大公因數(GCD), 二進位轉換(Binary Conversion)
**/

#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(const string &binary) {
    int sum = 0;
    for (char c : binary) {
        sum = sum * 2 + (c - '0'); 
    }
    return sum;
}

int main () {
	int t; 
	cin >> t;
	for (int Case = 1; Case <= t; Case++) {
		string s1, s2; 
		cin >> s1 >> s2;
		int n1 = binaryToDecimal(s1);
		int n2 = binaryToDecimal(s2);

		printf("Pair #%d", Case);
		if (__gcd(n1, n2) > 1) printf(": All you need is love!\n");
		else printf(": Love is not all you need!\n");
	}
	return 0;
}
