/*
 * Problem: "UVa 10188 - Automated Judge Script"
 *  Author: "Jia_coding"
 * 
 *     Tag: 字串(String)
**/

#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    int Case = 1;
    while (cin >> n && n) {
        string s;
        vector<string> sv1, sv2;
        
        cin.ignore();
        while(n--) {
            getline(cin, s);
            sv1.push_back(s);
        }

        cin >> m;
        cin.ignore();
        while(m--) {
            getline(cin, s);
            sv2.push_back(s);
        }
        
        
        printf("Run #%d: ", Case++);
        if (sv1 == sv2) {
            printf("Accepted\n");
            continue;
        }
        
        string S1 = "", S2 = "";
        for (auto s : sv1) {
            for (auto c : s) {
                if (isdigit(c)) S1 += c;
            }
        }
        
        for (auto s : sv2) {
            for (auto c : s) {
                if (isdigit(c)) S2 += c;
            }
        }
        
        if (S1 == S2) {
            printf("Presentation Error\n");
            continue;
        }
        else printf("Wrong Answer\n");
    }
    return 0;
}