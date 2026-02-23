/*
 * Problem: "UVa 499 - What's The Frequency, Kenneth?"
 *  Author: "Jia_coding"
 * 
 *     Tag: 哈希(Hash)
**/

#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    
    while (getline(cin, s) && s.size()) {
        map<char, int> Hash;
        
        int maxC = 0;
        char idC = 'a';
        for (auto c : s) {
            if (isalpha(c)) {
                Hash[c]++;
                maxC = max(maxC, Hash[c]);
            }
        }
        for (auto [u, v] : Hash) {
            if (v == maxC) cout << u;
        }
        printf(" %d\n", maxC);
    }
    return 0;
}