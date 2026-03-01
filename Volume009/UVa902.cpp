/*
 * Problem: "UVa 902 - Password Search"
 *  Author: "Jia_coding"
 * 
 *     Tag: 字串
**/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    while (cin >> n >> s) {
        int maxn = 0;
        string ans;
        map<string, int> Hash;
        for (int i = 0; i + n <= s.size(); i++) {
            string tmp = s.substr(i, n);
            Hash[tmp] ++;
            if (Hash[tmp] > maxn) {
                maxn = Hash[tmp];
                ans = tmp;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
