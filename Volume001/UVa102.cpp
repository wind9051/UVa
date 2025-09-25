/*
 * Problem: "UVa 102 - Ecological Bin Packing"
 *  GitHub: "https://github.com/wind9051/UVa"
 *  Notion: "https://titanium-cylinder-f1d.notion.site/00102-269d4158fd15802693c4edd4495f5161?source=copy_link"
 *  Author: "Jia_coding"
 * 
 *     Tag: 貪心(Greedy), 全排列
**/

#include <bits/stdc++.h>
using namespace std;

string ps[] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

int main() {
	int b1, g1, c1, b2, g2, c2, b3, g3, c3;
	while (cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3) {
	    int sum = b1 + g1 + c1 + b2 + g2 + c2 + b3 + g3 + c3;
	    
	    vector<int> cur(6);
		cur[0] = sum - b1 - c2 - g3;//BCG
		cur[1] = sum - b1 - g2 - c3;//BGC
		cur[2] = sum - c1 - b2 - g3;//CBG
		cur[3] = sum - c1 - g2 - b3;//CGB
		cur[4] = sum - g1 - b2 - c3;//GBC
		cur[5] = sum - g1 - c2 - b3;//GCB
		
		int cnt = 0, maxn = cur[0];
		for (int i = 0; i < 6; i++) {
			if (cur[i] < maxn) {
				maxn = cur[i];
				cnt = i;
			}
		}
		cout << ps[cnt] << " " << maxn << "\n";	
	}
	return 0;
}
