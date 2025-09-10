/*
 * Problem: "UVa 10198 - Counting"
 *  Author: "Jia_coding"
 * 
 *     Tag: 動態規劃(DP), 大數運算(Big Integer), 組合數列(Combinatorics)
**/

#include <bits/stdc++.h>
using namespace std;

int DP[1005][1005];
void init() {
    DP[1][0] = 2;
    DP[2][0] = 5; // 5 
    DP[3][0] = 3; DP[3][1] = 1; // 13
    for (int i = 4; i <= 1e3; i++) {
        for (int j = 0; j < 1e3; j++) {
            DP[i][j] = 2*DP[i-1][j] + DP[i-2][j] + DP[i-3][j];  
        }
        //for (int j = 0; j < 10; j++) cout<<DP[i][j]<<" "; cout<<endl;
        
        for (int j = 0; j < 1e3; j++) {
            DP[i][j+1] += DP[i][j] / 10; 
            DP[i][j] = DP[i][j] % 10; 
        }
        
        //for (int j = 0; j < 10; j++) cout<<DP[i][j]<<" "; cout<<endl;
    }
    /*
    for (int i = 1; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            cout<<DP[i][j]<< " ";
        }cout<<endl;
    }
    */
}

int main() {
    init();  
    
    int N;
    while (cin >> N) {
        int L = 1e3;
        while (DP[N][L] == 0) L--;
        //cout<<L<<endl;
        while (L >= 0) printf("%d", DP[N][L--]);
        printf("\n");
    }
    return 0;
}