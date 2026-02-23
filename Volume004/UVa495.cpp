/*
 * Problem: "UVa 495 - Fibonacci Freeze"
 *  Author: "Jia_coding"
 * 
 *     Tag: 大數（加法）
**/

#include <cstring>
#include <iostream>
using namespace std;

int fib[5005][305];//5000 len = 1045
void init() {
    memset(fib[0], 0, sizeof(fib[0]));
	fib[0][0] = 0;
	fib[1][0] = 1;
	fib[2][0] = 1;
	for (int i = 3; i <= 5000; i++) {
		for (int j = 0; j <= 300; j++) {
			fib[i][j] = fib[i-1][j] + fib[i-2][j];
		}
		for (int j = 0; j <= 300; j++) {
		    fib[i][j+1] += fib[i][j] / 10000;
		    fib[i][j] %= 10000;
		}
	}
}

int main () {
	init();
	int n;
	while (cin >> n) {
		printf("The Fibonacci number for %d is ", n);
		if (n == 0) {
		    cout << "0" << endl;
		    continue;
		}
		int end = 270; //1045/4
		while (fib[n][end] == 0) end--;
		for (int i = end; i >= 0; i--) {
			if (i != end) {
				string num = "";
				while (fib[n][i]) {
					num += fib[n][i] % 10 + '0';
					fib[n][i] /= 10;
				}
				for (int i = num.size(); i < 4; i++) cout << "0";
				for (int i = num.size()-1; i >= 0; i--) cout << num[i];
			}
			else cout << fib[n][i];
		}
		cout << endl;
	}
	return 0;
}