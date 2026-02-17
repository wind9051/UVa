/*
 * Problem: "UVa 1726 - Automatic Cheater Detection"
 *  Author: "Jia_coding"
 * 
 *     Tag: 二分搜(Binary Search) 
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, q, d;
    char s, r;
    
    cin >> t;
    while (t--) {
        
        cin >> q;
        vector<int> A, B; 
        for (int i = 0, Ai = 0, Bi = 0; i < q; i++) {
            cin >> d >> s >> r;
            if (s == '0' && r == 'i') A.push_back(d);
            if (s == '1' && r == 'c') B.push_back(d);
        }
        //sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        int cnt = 0;
        for (int i = 0; i < A.size(); i++) {
            auto it = upper_bound(B.begin(), B.end(), A[i]);
            cnt += B.end() - it;
        }
        printf("%d\n", cnt);
    }
    return 0;
}