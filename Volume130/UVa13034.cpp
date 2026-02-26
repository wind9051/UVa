/*
 * Problem: "UVa 13034 - Solve Everything :-)"
 *  Author: "Jia_coding"
 * 
 *     Tag: -
**/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int Case = 1; Case <= t; Case++) {
        int x;
        bool flag = 1;
        for (int i = 1; i <= 13; i++) {
            cin >> x;
            if (!x) flag = 0;
        }
        printf("Set #%d: %s\n", Case, flag ? "Yes" : "No");
    }
    return 0;
}
