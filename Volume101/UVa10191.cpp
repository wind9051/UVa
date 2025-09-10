/*
 * Problem: "UVa 10191 - Longest Nap"
 *  Author: "Jia_coding"
 * 
 *     Tag: 模擬(Simulation), 排序(Sorting), 貪心(Greedy)
**/

#include <bits/stdc++.h>
using namespace std;

struct Work {
    int L, R;
}; 

int main () {
    int t, Case = 1;
    while (cin >> t) {
        string ignore;
        int H1, M1, H2, M2;
        vector<Work> T(t+2);
        for (int i = 1; i <= t; i++) {
            scanf("%d:%d %d:%d", &H1, &M1, &H2, &M2);
            T[i].L = H1 * 60 + M1;
            T[i].R = H2 * 60 + M2;

            getline(cin, ignore);
        }
        T[0] = {600, 600}; //10:00
        T[t+1] = {1080, 1080}; //18:00
        
        sort(T.begin(), T.end(), [](Work & A, Work & B) {
            if (A.L == B.L) return A.R < B.R;
            else return A.L < B.L;
        });
        
        /*
        for (int i = 0; i <= t+1; i++) {
            cout<<T[i].L<<" -> "<<T[i].R<<endl;
        }
        */
        
        int nap = 0, now = 0;
        for (int i = 0; i <= t; i++) {
            if (nap < T[i+1].L - T[i].R) {
                nap = T[i+1].L - T[i].R;
                now = T[i].R;
            }
        }
        
        printf("Day #%d: the longest nap starts at %d:%02d and will last for ", Case++, now/60, now%60);
        if (nap/60) printf("%d hours and %d minutes.\n", nap/60, nap%60);
        else printf("%d minutes.\n", nap%60);
        
    }   
    return 0;
}