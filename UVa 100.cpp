//UVA100 - The 3n+1 problem 
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
