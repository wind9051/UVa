/*
 * Problem: "UVa 13257 - License Plates"
 *  Author: "Jia_coding"
 * 
 *     Tag: DP
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; 
    cin >> T;
    while (T--) {
        string S;
        cin >> S;

        bool seen1[26] = {0};
        bool seen2[26][26] = {0};
        bool seen3[26][26][26] = {0};

        for (char ch : S) {
            int c = ch - 'A';

            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (seen2[i][j]) {
                        seen3[i][j][c] = true;
                    }
                }
            }
                
            for (int i = 0; i < 26; i++) {
                if (seen1[i]) {
                    seen2[i][c] = true;
                }
            }

            seen1[c] = true;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                for (int k = 0; k < 26; k++)
                    if (seen3[i][j][k]) ans++;

        cout << ans << "\n";
    }
}
