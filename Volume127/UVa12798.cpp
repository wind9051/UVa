/*
 * Problem: "UVa 12798 - Handball"
 *  Author: "Jia_coding"
 * 
 *     Tag: 
**/

#include<bits/stdc++.h>
using namespace std;

int main (){
    int n, m;
    while(cin >> n >> m) {
        int x = 0;
        vector<bool> P(n, 1); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> x;
                if (x == 0) P[i] = 0;
            }
        }
        int cnt = 0;
        for (auto cur : P) {
            if (cur) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}

