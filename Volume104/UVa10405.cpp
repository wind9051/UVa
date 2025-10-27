/*
 * Problem: "UVa 10405 - Longest Common Subsequence"
 *  Author: "Jia_coding"
 *
 *     Tag: 動態規劃(DP), 最長公共子序列(LCS)
 *
**/

#include <bits/stdc++.h>
using namespace std;

int main () {
    string s1, s2;
    while (getline(cin, s1)) {
        getline(cin, s2);

        vector<vector<int>> LCS(1005, vector<int>(1005, 0));
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if (s1[i-1] == s2[j-1]) LCS[i][j] = LCS[i-1][j-1] + 1;
                else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
        printf("%d\n", LCS[s1.size()][s2.size()]);
    }
    return 0;
}