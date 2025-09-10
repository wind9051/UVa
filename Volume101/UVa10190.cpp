/*
 * Problem: "UVa 10190 - Divide But Not Quite Conquer"
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學(Math), 除法(division)
**/

#include <vector>
#include <iostream>
using namespace std;
int main () {
	int n, m; //num mod
	while (cin >> n >> m) {
		vector <int> num;
		bool boring = false;
		if (n == 0 || n == 1 || m == 0 || m == 1) {//mod 1 or 0 error 
			cout << "Boring!\n";
			continue;
		}
		else {
			num.push_back(n);
			while (n > 1) {
				if (n % m == 0) {
					n /= m;
					num.push_back(n);	
				}
				else {
					boring = true;
					break;
				}
			}	
		}
		
		if (boring) printf("Boring!\n");
		else {	
			for (int i = 0; i < num.size(); i++) {
				if (num[i] == 1) cout << num[i]; 
				else cout << num[i] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}