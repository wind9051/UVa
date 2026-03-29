/*
 * Problem: "UVa 13287 - Shattered Cake"
 *  Author: "Jia_coding"
 * 
 *     Tag: 幾何-矩形
**/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll W, N;
    while (cin >> W >> N) {
        ll A = 0;
        for (int i = 0; i < N; i++) {
            ll Wi, Li;
            cin >> Wi >> Li;
            A += Wi * Li;
        }
        
    	cout << A / W << endl;
    }
	return 0;
}

