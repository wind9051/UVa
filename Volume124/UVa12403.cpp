/*
 * Problem: "UVa 12403 - Save Setu"
 *  Author: "Jia_coding"
 * 
 *     Tag: 
**/

#include<iostream>
using namespace std;
int sum = 0;

int main() {
	int t;  
	cin >> t;
	while (t--) {
		string s; 
		cin >> s;
		
		if (s == "donate") {
			int n; 
			cin >> n;
			sum += n;
		}
		else {
			cout << sum << endl;
		}
	}
	return 0;
} 
