/*
 * Problem: "UVa 13190 - Rockabye Tobby"
 *  Author: "Jia_coding"
 * 
 *     Tag: 最大公因數(GCD)
**/

//UVA
#include <bits/stdc++.h>
using namespace std;

struct Mem {
	string N; //name 
	int F; //frecuency 
}; 

int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
		    cin >> n >> k;  
		    vector<Mem> M(n);
		    for (int i = 0; i < n; i++) {
		      cin >> M[i].N >> M[i].F;
		    }
		    
        int d = M[0].F;
        for (int i = 0; i < n; i++) {
            d = __gcd(d, M[i].F);
        }
        
        
        int cur = d, cnt = 0;
        while (cnt < k) {
            for (int i = 0; i < n && cnt < k; i++){
                if (cur % M[i].F == 0) {
                    printf("%d %s\n", cur, M[i].N.c_str());
                    cnt++;
                }
            }
            cur += d;
        }
    }
    return 0;
}
