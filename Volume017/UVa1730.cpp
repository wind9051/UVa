/*
 * Problem: "UVa 1730 - Sum of MSLCM"
 *  GitHub: "https://github.com/wind9051/UVa"
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學, 因數, LCM, 前綴和
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 20000001;

int main() {
    vector<ll> MSLCM(MAX, 1);
    for (int i = 2; i <= MAX-1; i++) {
        for (int j = i; j <= MAX-1; j+=i) {
            MSLCM[j] += i;
        }
    }
    for (int i = 3; i <= MAX-1; i++) {
        MSLCM[i] += MSLCM[i-1];
    }
    
    int n;
    while (cin >> n && n) {
        printf("%lld\n", MSLCM[n]);
    }
    return 0;
}
