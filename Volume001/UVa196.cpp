/*
 * Problem: "UVa 196 - Spreadsheet"
 *  Author: "Jia_coding"
 * 
 *     Tag: DFS, 記憶化
**/

#include <bits/stdc++.h>
using namespace std;

int compute(int i, int j, vector<vector<int>> & N, vector<vector<string>> &Fnc) {
    if (Fnc[i][j] == "!") return N[i][j];
    
    int sum = 0;
    string cell;
    stringstream ss(Fnc[i][j]);
    while (getline(ss, cell, '+')) {
        int C = 0, L = 0;
        while (isalpha(cell[L])) {
            C = C*26 + cell[L] - 'A' + 1;
            L++;
        }
        int R = stoi(cell.substr(L));
        sum += compute(R-1, C-1, N, Fnc);
    }
    Fnc[i][j] = "!";
    
    return N[i][j] = sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int C, R;
        cin >> C >> R;
        vector<vector<int>> Num(R, vector<int>(C, -1));
        vector<vector<string>> Fnc(R, vector<string>(C, "!"));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> s;
                if (s[0] == '=') Fnc[i][j] = s.substr(1);
                else Num[i][j] = stoi(s);
            }
        }
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                printf("%d%c", compute(i, j, Num, Fnc), (j != C-1) ? ' ' : '\n');
            }
        }
    }
    return 0;
}