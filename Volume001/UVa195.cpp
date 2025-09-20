/*
 * Problem: "UVa 195 - Anagram"
 *  Author: "Jia_coding"
 * 
 *     Tag: 排列組合
**/

#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(char a, char b) {
    char Ua = toupper(a);
    char Ub = toupper(b);
    if (Ua == Ub) return a < b;
    
    return Ua < Ub;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end(), cmp);
        
        do {
            cout << s << endl;
        }while (next_permutation(s.begin(), s.end(), cmp));
    }
    return 0;
}