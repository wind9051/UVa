/*
 * Problem: "UVa 12770 - Palinagram"
 *  Author: "Jia_coding"
 * 
 *     Tag: 回文
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s && s != "#") {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        vector<int> odd;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) odd.push_back(i);
        }

        if (odd.size()) odd.pop_back();

        if (odd.size() == 0) {
            cout << "\n";
            continue;
        }

        vector<int> add(26, 0);
        for (int x : odd) {
            cout << char(x + 'a');
        }
        cout << "\n";
    }

    return 0;
}