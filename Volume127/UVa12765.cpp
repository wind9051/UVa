/*
 * Problem: "UVa 12765 - Factorial Products"
 *  Author: "Jia_coding"
 * 
 *     Tag: 階層
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // factorial Prime Count
    vector<vector<int>> Pcount(10, vector<int>(10, 0));
    Pcount[2][2] = 1;
    Pcount[3][2] = 1; Pcount[3][3] = 1;
    Pcount[4][2] = 3; Pcount[4][3] = 1;
    Pcount[5][2] = 3; Pcount[5][3] = 1; Pcount[5][5] = 1;
    Pcount[6][2] = 4; Pcount[6][3] = 2; Pcount[6][5] = 1;
    Pcount[7][2] = 4; Pcount[7][3] = 2; Pcount[7][5] = 1; Pcount[7][7] = 1;
    Pcount[8][2] = 7; Pcount[8][3] = 2; Pcount[8][5] = 1; Pcount[8][7] = 1;
    Pcount[9][2] = 7; Pcount[9][3] = 4; Pcount[9][5] = 1; Pcount[9][7] = 1;

    int N, M;
    while (cin >> N >> M && (N || M)) {
        if (N == 0 && M == 0) break;

        vector<int> cnt1(10, 0), cnt2(10, 0);

        for (int i = 0, d; i < N; i++) {
            cin >> d;
            for (int j = 0; j <= 9; j++) {
                cnt1[j] += Pcount[d][j];
            }
        }

        for (int i = 0, d; i < M; i++) {
            cin >> d;
            for (int j = 0; j <= 9; j++) {
                cnt2[j] += Pcount[d][j];
            }
        }

        if (cnt1[2] == cnt2[2] && cnt1[3] == cnt2[3] && cnt1[5] == cnt2[5] && cnt1[7] == cnt2[7])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}