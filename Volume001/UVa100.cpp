/*
 * Problem: "UVa 100 - The 3n+1 problem"
 *  Author: "Jia_coding"
 *
 *     Tag: 數學(Math), 遞迴(Recursion), Collatz猜想(3n+1)
**/

#include <bits/stdc++.h>
using namespace std;

int cycle_len(int n) {
    int cnt = 1;
    while (n != 1) {
        if (n % 2) n = 3 * n + 1;
        else n = n / 2;
        cnt++;
    }
    return cnt;
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        int maxlen = 0;
        for (int i = min(a, b); i <= max(a, b); i++) {
            maxlen = max(maxlen, cycle_len(i));
        }
        printf("%d %d %d\n", a, b, maxlen);
    }
    return 0;
}
