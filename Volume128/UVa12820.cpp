/*
 * Problem: "UVa 12820 - Cool Word"
 *  Author: "Jia_coding"
 * 
 *     Tag: 哈希(Hash)
**/

#include <map>
#include <set>
#include <iostream>
using namespace std;
int main () {
	int t, Case = 1;
	while (cin >> t) {
		cin.ignore();
		
		int cnt = 0;
		while (t--) {
			string s;
			getline(cin, s);			
			
			map<char, int> alpha;
			for (char ch : s) alpha[ch] ++;

			bool cool = 1;
			set<int> vis;
			for (auto [key, cnt] : alpha) {
				if (!vis.count(cnt)) vis.insert(cnt);
				else {
					cool = 0;
					break;
				}
			}
			if (cool && vis.size() != 1) cnt++;			
		}
		printf("Case %d: %d\n", Case++, cnt);
	}
	return 0;
}
