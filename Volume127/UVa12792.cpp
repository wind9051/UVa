/*
 * Problem: "UVa 12792 - Shuffled Deck"
 *  Author: "Jia_coding"
 * 
 *     Tag: 排序(循環)
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;  
    while (cin >> n) {
        int x = 2, cnt = 1;
        int L = 4;
        while (x != 1) {
            if (x <= n/2) x = 2 * x;
            else x = 2 * (x - n/2) - 1;
            cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
