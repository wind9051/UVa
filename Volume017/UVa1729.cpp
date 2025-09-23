/*
 * Problem: "UVa 1729 - Owllen"
 *  GitHub: "https://github.com/wind9051/UVa"
 *  Author: "Jia_coding"
 * 
 *     Tag: 字串, 哈希(Hash), LCS(最短)
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, Case = 1;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        vector<int> alpha(26, 0);
        for (auto c : s) alpha[c - 'a']++;
        printf("Case %d: %d\n", Case++, *min_element(alpha.begin(), alpha.end()));
    }
    return 0;
}