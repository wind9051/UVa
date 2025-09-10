/*
 * Problem: "UVa 10146 - Dictionary"
 *  Author: "Jia_coding"
 *
 *     Tag: 字串(String), 前綴(Prefix), 字典樹(Dictionary Tree)
 *          
 *
**/

#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    cin.ignore();
    string ig;
    getline(cin, ig); //ignore();
    while (t--) {
        int spaces = 0;
        string word, preWord = "";
        
        while (getline(cin, word)) {
            if (!word.size()) break;

            int cnt = 0;
            for (int i = 0; i < min(word.size(), preWord.size()); i++) {
                if (word[i] != preWord[i]) break;
                cnt++;
            }
            spaces = min(spaces+1, cnt);

            for (int i = 0; i < spaces; i++) printf(" ");
            cout << word << endl;

            preWord = word;
        }
        if (t) printf("\n");
    }
    return 0;
}