/*
 * Problem: "UVa 12750 - Keep Rafa at Chelsea"
 *  Author: "Jia_coding"
 * 
 *     Tag: -
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;

        int cnt = 0;
        bool fired = false;
        for (int i = 1; i <= n; i++) {
            char c;
            cin >> c;

            if (c == 'W') {
                cnt = 0;
            } 
            else {
                cnt++;
            }

            if (cnt == 3 && !fired) {
                cout << "Case " << tc << ": " << i << "\n";
                fired = true;
            }
        }

        if (!fired) {
            cout << "Case " << tc << ": Yay! Mighty Rafa persists!\n";
        }
    }

    return 0;
}