/*
 * Problem: "UVa 10963 - The Swallowing Ground"
 *  Author: "Jia_coding"
 * 
 *     Tag: coordinate(座標)
 * 
 *    Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1904
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin >> t;
	while (t--) {
		int n;
        cin >> n;


		bool flag = true;
        int y1, y2, d = 0; //U, D
		for (int i = 0; i < n; i++) {
			cin >> y1 >> y2;
			if (i == 0) d = abs(y1 - y2);
            else {
                if (d != abs(y1 - y2)) {
                    flag = false;
                }
            }
		}

        printf(flag ? "yes\n" : "no\n");

        if (t) printf("\n");
	}
	return 0;
}

