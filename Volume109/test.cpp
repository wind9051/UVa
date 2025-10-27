/*
 * Problem: "UVa 10100 - Longest Match"
 *  Author: "Jia_coding"
 *
 *     Tag: 動態規劃(DP), 最長公共子序列(LCS)
 *
**/

#include <bits/stdc++.h>
using namespace std;

int main () {
    int Case = 1;
    string s1, s2;
    while (getline(cin, s1)) {
        getline(cin, s2);
        
        s1 += "#";
        s2 += "#";
        
        vector<string> st1, st2; 
        string now = ""; 
        for (auto ch : s1) { 
            if (isdigit(ch) || isalpha(ch)) now += ch; 
            else { 
                if (now != "") st1.push_back(now); 
                now = ""; 
            }
        }
        for (auto ch : s2) { 
            if (isdigit(ch) || isalpha(ch)) now += ch; 
            else { 
                if (now != "") st2.push_back(now); 
                now = "";
            }
        }
        
        vector<vector<int>> LCS(1005, vector<int>(1005, 0)); 
        for (int i = 1; i <= st1.size(); i++) { 
            for (int j = 1; j <= st2.size(); j++) { 
                if (st1[i-1] == st2[j-1]) LCS[i][j] = LCS[i-1][j-1] +1; 
                else LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]); 
            }
        }
        printf("%2d. ", Case++);
        if (s1.size() == 1 || s2.size() == 1) printf("Blank!\n");
        else printf("Length of longest match: %d\n", LCS[st1.size()][st2.size()]);
    }
    return 0;
}