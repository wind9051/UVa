/*
 * Problem: "UVa 10892 - LCM Cardinality"
 *  Author: "Jia_coding"
 *
 *     Tag: 數學(Math), 最小公倍數(LCM), 因數分解(Factorization)
 *
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll GCD(ll a, ll b) {
  if (b == 0) return a;
  return GCD(b, a%b);
}

ll LCM(ll m, ll n) {
    return (m*n / GCD(m, n));
}

int main() {
    int n;
    while (cin >> n && n) {

        vector<int> fac; //factor
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                fac.push_back(i);
                if (i != n/i)  fac.push_back(n/i);
            }
        }
        
        //for (int x : fac) cout<<x<<" ";
        //cout<<endl;
        
        int cnt = 0;
        for (int i = 0; i < fac.size(); i++) {
            for (int j = i; j < fac.size(); j++) {
                if (LCM(fac[i], fac[j]) == n) {
                  cnt++;
                  //cout<<"("<<fac[i]<<","<<fac[j]<<")"<<endl;
                }
            }
        }
        printf("%d %d\n", n, cnt);
        
    }
	return 0;
}
