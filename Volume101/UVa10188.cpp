/*
 * Problem: "UVa 10188 - Automated Judge Script"
 *  Author: "Jia_coding"
 * 
 *     Tag: 字串(String)
**/

#include <iostream>
using namespace std;

int n, m;
string s, s1, s2;

int main() {
    int Case = 1;
    while (cin >> n && n) {
        s1 = "";
        cin.ignore();
        while(n--) {
            getline(cin, s);
            s1 += s;
        }
        int l = s1.size();

        cin >> m;
        s2 = "";
        cin.ignore();
        while(m--) {
            getline(cin, s);
            s2 += s;
        }

        if (s1 == s2) {
            printf("Run #%d: Accepted %d\n", Case++, l);
            continue;
        }

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == ' ') {
                s1.erase(i, 1);
                i--;
            }
        }
        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] == ' ') {
                s2.erase(i, 1);
                i--;
            }
        }
        
        if (s1 == s2) {
            printf("Run #%d: Presentation Error %d\n", Case++, l);
            continue;
        }
        else printf("Run #%d: Wrong Answer %d\n", Case++, l);
    }
    return 0;
}