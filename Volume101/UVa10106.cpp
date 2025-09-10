/*
 * Problem: "UVa 10106 - Product"
 *  Author: "Jia_coding"
 * 
 *     Tag: 大數(Big Integer)
**/

#include <bits/stdc++.h>
using namespace std;

string mul_Big(string x, string y) {
    int n = x.size();
    int m = y.size();
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    
    vector<int> ans(n + m + 5, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i+j] += (x[i] - '0') * (y[j] - '0');
            ans[i+j + 1] += ans[i+j] / 10;
            ans[i+j] %= 10;
        }
    }
    
    string res = "";
    int L = n+m;
    while (ans[L] == 0) L--;
    while (L >= 0) res += (ans[L--] + '0');
    
    if (res.empty()) return "0";
    return res;
}

int main() {
    string a, b;
    while (cin >> a >> b) {
      string ans = mul_Big(a, b);
      cout << ans <<endl;
    }
    return 0;
}
