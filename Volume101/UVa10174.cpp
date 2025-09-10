/*
 * Problem: "UVa 10174 - Couple-Bachelor-Spinster Numbers."
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學(Math), 平方差(Difference of Squares)
**/

#include <bits/stdc++.h>
using namespace std;

int main () {
    string s, sN1, sN2;
    while (getline(cin, s)) {
        stringstream ss(s);
        ss >> sN1;
        if (ss >> sN2) {
            int cnt = 0;
            int L = stoi(sN1), R = stoi(sN2);
            if (L & 1) L++;
            for (int n = L; n <= R; n+=2) {
                if (n % 4) cnt++; //2 6 10
            }
            printf("%d\n", cnt);
        } 
        else {
            int n = stoi(sN1);
            if (n == 0) printf("1 1\n");
            //奇數
            else if (abs(n) & 1) {
                //N = 1*N   A = (N+1)/2,  B = (N-1)/2
                int A = (abs(n)+1) / 2;
                int B = (abs(n)-1) / 2;
                if (n > 0) printf("%d %d\n", A, B);
                else printf("%d %d\n", B, A);
            } 
            //偶數
            else {
                if (n % 4 == 0) {
                    //N = 2*2R   A = (2R+2)/2,  B = (2R-2)/2
                    int x = 2, y = abs(n) / 2;
                    int A = (x+y) / 2;
                    int B = (y-x) / 2;
                    if (n > 0) printf("%d %d\n", A, B);
                    else printf("%d %d\n", B, A);
                }
                //2 6 10 14
                else {
                    printf("Bachelor Number.\n");
                }
            }
        }
    }
    return 0;
}