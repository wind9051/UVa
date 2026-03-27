/*
 * Problem: "UVa 960 - Gaussian Primes"
 *  Author: "Jia_coding"
 * 
 *     Tag: 複數
**/

#include <bits/stdc++.h>
using namespace std;

int is_prime(int x) {
    if (x < 2) return 0;
    
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a != 0 && b != 0) {
            int sum = a*a + b*b;
            printf("%c\n", (is_prime(sum)) ? 'P' : 'C');
        }
        else if (a == 0) {
            int sum = abs(b);
            printf("%c\n", (is_prime(sum) && sum % 4 == 3) ? 'P' : 'C');
        }
        else if (b == 0) {
            int sum = abs(a);
            printf("%c\n", (is_prime(sum) && sum % 4 == 3) ? 'P' : 'C');
        }
    }
    return 0;
}
