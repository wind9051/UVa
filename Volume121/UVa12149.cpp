/*
 * Problem: "UVa 12149 - Feynman"
 *  Notion: ""
 *  Author: "Jia_coding"
 * 
 *     Tag: 
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> Sum(105, 0);
    for (int i = 1; i <= 100; i++) {
        Sum[i] = Sum[i-1] + i*i;
    }
    int n;
    while (cin >> n && n) {
        cout<<Sum[n]<<endl;
    }
    return 0;
}