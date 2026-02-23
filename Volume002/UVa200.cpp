/*
 * Problem: "UVa 200 - Rare Order"
 *  Author: "Jia_coding"
 * 
 *     Tag: 拓樸, 字典樹
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    vector<string> Word;
    
    set<char> map;
    
    int maxL = 0;

    while (cin >> s && s != "#") {
        Word.push_back(s);
        
        maxL = max(maxL, (int)s.size());
    }

    for (int j = 0; j < maxL; j++) {
        for (int i = 0; i < Word.size(); i++) {
            if (j < Word[i].size() && !map.count(Word[i][j])) {
                map.insert(Word[i][j]);
                cout << Word[i][j];
            }
        }
       
    }
    cout << endl;

    return 0;
}