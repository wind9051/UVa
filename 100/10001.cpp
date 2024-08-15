/*
 * Title:  "UVa10001 - Garden of Eden"
 * Author: "Jia_coding"
 * Date:   "2024/08/16"
 */

#include <bits/stdc++.h>
using namespace std;

int id, len, reach;
vector<int> S(32, 0);
vector<int> N(32, 0);

bool cell(int L, int C, int R) {
    int v = id & (1 << ((L << 2) | (C << 1) | R));
    if (v) return 1;
    else return 0;
}

void Auto(int base) {
    if (base == len) {
        if (cell(N[len-2], N[len-1], N[0]) != S[len-1]) return;
        if (cell(N[len-1], N[0], N[1]) != S[0]) return;
        reach++;
    }
    
    for (int i = 0; i < 2; i++) {
        N[base] = i;
        //for (int k = 0; k < 5; k++) cout<<N[k]<<" ";cout<<endl;
        if (base >= 2 && cell(N[base-2], N[base-1], N[base]) != S[base-1]) continue;
        Auto(base+1);
    }
}

int main () {
    string s;
    while (cin >> id >> len >> s) {
        for (int i = 0; i < len; i++) S[i] = s[i]-'0';
        
        reach = 0;
        Auto(0);

        if (reach) printf("REACHABLE\n");
		else printf("GARDEN OF EDEN\n");
    }
    return 0;
}
//11011100
