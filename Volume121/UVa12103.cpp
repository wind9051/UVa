/*
 * Problem: "UVa 12103 - Leonardo’s Notebook"
 *  Author: "Jia_coding"
 * 
 *     Tag: 排列(循環)
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        vector<int> cnt(27, 0);
        vector<bool> vis(26, false);
        for (int i = 0; i < 26; ++i) {
            int cur = i;
            int len = 0;
            while (!vis[cur]) {
                vis[cur] = true;
                cur = s[cur] - 'A';
                len++;
            }
            cnt[len]++;
        }
        bool flag = true;
        for (int i = 2; i <= 26; i += 2) {
            if (cnt[i] & 1) {
                flag = false;
                break;
            }
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
