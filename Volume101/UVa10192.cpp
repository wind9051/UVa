/*
 * Problem: "UVa 10192 - Vacation"
 *  Author: "Jia_coding"
 *
 *     Tag: 動態規劃(DP), 最長公共子序列(LCS)
 *
**/

#include <bits/stdc++.h>
using namespace std;

string initStr(string & s) {
    string now = "";
    for (char ch : s) {
        if (isalpha(ch) || isdigit(ch) || isspace(ch)) now += ch;
    }
    return now;
}

int main () {
  int Case = 1;
    string s1, s2;
    while (getline(cin, s1) && s1 != "#") {
        getline(cin, s2);

        //s1 = initStr(s1);
        //s2 = initStr(s2);

        vector<vector<int>> LCS(105, vector<int>(105, 0));
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if (s1[i-1] == s2[j-1]) LCS[i][j] = LCS[i-1][j-1] + 1;
                else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n", Case++, LCS[s1.size()][s2.size()]);
    }
    return 0;
}