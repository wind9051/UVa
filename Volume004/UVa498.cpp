/*
 * Problem: "UVa 498 - Polly the Polynomial"
 *  Author: "Jia_coding"
 * 
 *     Tag: 多項式
**/

#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    while (getline(cin, s)) {
        int val;
        
        stringstream ss1(s);
        vector<int> C;
        while (ss1 >> val) C.push_back(val);
        
        getline(cin, s);
        stringstream ss2(s);
        vector<int> X;
        while (ss2 >> val) X.push_back(val);
        
        vector<int> ans(X.size());
        for (int i = 0; i < X.size(); i++) {
            long long sum = 0, n = C.size()-1;
            for (int j = 0; j < C.size(); j++) {
                sum += pow(X[i], n-j) * C[j];
            }
            ans[i] = sum;
        }
        for (int i = 0; i < X.size(); i++) {
            printf("%d%c", ans[i], (i != X.size()-1)? ' ' : '\n');
        }
        
    }
    return 0;
}