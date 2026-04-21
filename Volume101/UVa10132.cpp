/*
 * Problem: "UVa 10132 - File Fragmentation"
 *  Author: "Jia_coding"
 * 
 *     Tag: 模擬, 字串(String), 排列組合, 雜湊(Hash)
**/

#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    getline(cin, s); // ignore
    while (t--) {
        vector<string> chip;
        while (getline(cin, s) && s.size() != 0) {
            chip.push_back(s);
        }
        
        int L = chip.size();
        
        map<string, int> Hash;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                if (i != j) {
                    Hash[chip[i]+chip[j]]++;
                }
            }
        }
        
        for (auto [u, v] : Hash) {
            if (v >= L/2) cout<<u<<endl;
        }
        if (t) printf("\n");
    }
    return 0;
}

/*
  file = 01210
  [0, 1210]   [01, 210]
  
  排列: L(L-1)
*/