/*
 * Problem: "UVa 100 - The 3n+1 problem"
 *  Notion: "https://titanium-cylinder-f1d.notion.site/00100-269d4158fd15801cb8ccd533d92cabab?source=copy_link"
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學(Math), 遞迴(Recursion), Collatz猜想(3n+1)
**/

#include <iostream>
using namespace std;

int cycle_len(int n, int cnt) {
    if (n == 1) return cnt;
    if (n % 2) return cycle_len(3 * n + 1, cnt + 1);
    else return cycle_len(n/2, cnt + 1);
}

int main() {
	int a, b;
	while (cin >> a >> b) {	
		int maxlen = 0;
		for (int i = min(a, b); i <= max(a, b); i++) {
			int cnt = 1;
			maxlen = max(maxlen, cycle_len(i, cnt));
		}
		printf("%d %d %d\n", a, b, maxlen);
	}	
	return 0;
}