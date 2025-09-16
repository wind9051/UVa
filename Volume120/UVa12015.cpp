/*
 * Problem: "UVa 12015 - Google is Feeling Lucky"
 *  Author: "Jia_coding"
 * 
 *     Tag: 哈希(Hash) 
**/

#include<iostream>
using namespace std;

struct Fec {
	string n;
	int f;
};
Fec F[10];

int main() {
	int t, Case = 1; 
	cin >> t;
	while (t--) {
  		int maxn = 0;//maxrelevance
    	for (int i = 0; i < 10; i++) {
      		cin >> F[i].n >> F[i].f;   
			    maxn = max(F[i].f, maxn);      
    	}
    	printf("Case #%d:\n", Case++);
    	for (int i = 0; i < 10; i++) {
      		if (maxn == F[i].f) cout << F[i].n << endl;        
    	}   	
	}
	return 0;
}