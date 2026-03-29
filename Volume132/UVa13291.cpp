/*
 * Problem: "UVa 13291 - Frosting on the Cake"
 *  Author: "Jia_coding"
 * 
 *     Tag: 幾何(矩形)
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

//long long n , a[100010] , b[100010] , ans[3] , suma[3] , sumb[3];
int main() {
    ll n;
    while (cin >> n) {
        vector<ll> A(n+1, 0), B(n+1, 0);
        vector<ll> sumA(3, 0), sumB(3, 0);
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            sumA[i % 3] += A[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> B[i];
            sumB[i % 3] += B[i];
        }
        
        vector<ll> Ans(3, 0);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Ans[(i+j)%3] += sumA[i] * sumB[j];
            }   
        }
        cout << Ans[0] << " " << Ans[1] << " " << Ans[2] << endl;
    }
    return 0;
}
