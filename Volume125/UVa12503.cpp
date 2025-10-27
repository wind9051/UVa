/*
 * Problem: "UVa 12503 - Robot Instructions"
 *  Author: "Jia_coding"
 * 
 *     Tag: 棋盤 - 陣列
**/

#include <vector>
#include <iostream>
using namespace std;
int main() {
	int t; 
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		vector<int> move;
		move.clear();
		move.push_back(0);

		int pos = 0;
		for (int i = 1; i <= n; i++) {
			string s; 
			cin >> s;
			if (s == "LEFT") move.push_back(-1);
			else if (s == "RIGHT") move.push_back(1);
			else {
				int same;
				cin >> s >> same;
				move.push_back(move[same]);
			}
			pos += move[i]; 
		}	
		cout << pos << endl;
	}
	return 0;
}
