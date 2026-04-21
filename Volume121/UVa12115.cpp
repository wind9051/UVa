/*
 * Problem: "UVa 12115 - Nested Squares"
 *  Author: "Jia_coding"
 * 
 *     Tag: 矩陣
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        string s;
        int r1, c1, r2, c2, q;
    
        cin >> s >> q;
        cout << "Square " << tc << ":" << endl;
        for (int Q = 1; Q <= q; Q++) {
            cin >> r1 >> c1 >> r2 >> c2;
            
            int len = s.size();
            cout << "Query " << Q << ":" << endl;
            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    cout << s[len - max(abs(len - i), abs(len - j)) - 1];
                }
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}