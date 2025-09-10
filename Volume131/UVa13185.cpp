/*
 * Problem: "UVa 13185 - DPA Numbers I"
 *  Author: "Jia_coding"
 * 
 *     Tag: 因數(完全/虧數/盈數)
**/

#include <bits/stdc++.h>
using namespace std;

int main () {
	  int t; 
  	cin >> t;
  	while (t--) {
    		int n; 
    		cin >> n;
    		
    		int sum = 1;
    		for (int i = 2; i*i <= n; i++) {
      			if (n % i == 0) {
      			    sum += i;
      				  if (i != n / i) sum += n / i;
      			}
    		}
    		if (sum < n) printf("deficient\n");
    		else if (sum > n) printf("abundant\n");
    		else printf("perfect\n");
  	}
  	return 0;
}
