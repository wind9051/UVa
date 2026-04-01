/*
 * Problem: "UVa 10115 - Automatic Editing"
 *  Author: "Jia_coding"
 * 
 *     Tag: 字串
**/

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (cin >> n && n) { 
        cin.ignore(); 
        
        string s1, s2;
        vector<vector<string>> dic(n, vector<string>(2, "")); 
        for (int i = 0; i < n; i++) {
            getline(cin, dic[i][0]); 
            getline(cin, dic[i][1]);
        }
        
        string s;
        getline(cin, s); 
        
        for (auto v : dic) { 
            while (s.find(v[0]) != string::npos) { 
                size_t cnt = s.find(v[0]); 
                s = s.substr(0, cnt) + v[1] + s.substr(cnt+v[0].size()); 
            }
        }

        cout << s << endl; 
    }
    return 0;
}