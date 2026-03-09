/*
 * Problem: "UVa 941 - Permutations"
 *  Author: "Jia_coding"
 * 
 *     Tag: 排組(排列)
**/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> initFac() {
    vector<ll> fac(21, 1);
    for (int i = 1; i <= 20; i++) {
        fac[i] = fac[i-1] * i;
    }
    return fac;
}

int main() {
    vector<ll> fac = initFac();

    int T;
    cin >> T;
    while (T--) {
        ll N;
        string s;
        cin >> s >> N;

        sort(s.begin(), s.end());

        vector<char> chars(s.begin(), s.end());
        
        string ans = "";
        for (int i = s.size(); i >= 1; i--) {
            ll block = fac[i - 1];
            ll index = N / block;
            N %= block;

            ans += chars[index];
            chars.erase(chars.begin() + index);
        }

        cout << ans << "\n";
    }

    return 0;
}