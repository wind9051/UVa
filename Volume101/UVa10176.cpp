/*
 * Problem: "UVa 10176 - Ocean Deep! - Make it shallow!!"
 *  Author: "Jia_coding"
 * 
 *     Tag: 進制轉換 - 2bit, 模數(MOD)
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 131071;

int main() {
    string s, buf;
    while (cin >> buf) {
        s = buf;
        while (buf.back() != '#') {
            cin >> buf;
            s += buf;
        }
        s.pop_back();
        //cout<<s<<endl;
        
        ll mul = 1, ans = 0;
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i]-'0') {
                ans += mul;
                ans %= MOD;
            }
            
            mul = mul * 2 % MOD;
        }
        //ans %= MOD;
        if (ans) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
