/*
 * Problem: "UVa 12788 - Smooth Factor"
 *  Author: "Jia_coding"
 * 
 *     Tag: 雙指針
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (n == 1) {
            cout << "1\n";
            continue;
        }

        int L = 0, M = 0, R = 1;
        int cnt = 0, maxL = 0;
        while (R < n) {
            if (a[R-1] > a[R]) {
                L = M;
                M = R;
            }
            maxL = max(maxL, R - L + 1);

            R++;
        }
        cout << maxL << "\n";
    }
    return 0;
}