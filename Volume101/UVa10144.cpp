/*
 * Problem: "UVa 10144 - Expression"
 *  Author: "Jia_coding"
 * 
 *     Tag: 布林代數(Boolean Algebra), 數位邏輯(Digital Logic)
 *     
**/

#include <bits/stdc++.h>
using namespace std;

vector<string> C(105, "");

string NAND(string X, string Y) {
    return "(" + X + "|" + Y + ")";
}

string OR(string X, string Y) {
    return "((" + X + "|" + X + ")|(" + Y + "|"+ Y + "))";
}

void init() {
    C[1] = "((A0|B0)|(A0|B0))";
    for (int i = 2; i <= 100; i++) {
        string S = "";
        // X^Y = (x|y)|(x|y)
        string Ai = "A" + to_string(i-1);
        string Bi = "B" + to_string(i-1);
        
        string nand_AB = NAND(Ai, Bi);
        string or_AB = OR(Ai, Bi);
        
        S += "(" + nand_AB + "|(" + C[i-1] + "|" + or_AB + "))";
        C[i] = S;
    }
}


int main() {
    init();
  
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << C[n] << endl;
      
        if (t) printf("\n");
    }
    return 0;
}