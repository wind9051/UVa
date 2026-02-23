/*
 * Problem: "UVa 299 - Train Swapping"
 *  Author: "Jia_coding"
 * 
 *     Tag: 排序(Sort) - 冒泡(Bubble Sort)
**/

//UVA299 Train Swapping 
#include <bits/stdc++.h>
using namespace std; 

int main () {
	int t; cin >> t;
	while (t--) {
		int n; 
		cin >> n;
		
		vector<int> train(55);
		for (int i = 0; i < n; i++) {
			cin >> train[i];
		}
		
		int cnt = 0;
		//Bubble sort
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n-1 -i; j++) {
				if (train[j] > train[j+1]) {
					swap(train[j], train[j+1]);
					cnt++;	
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n", cnt);
	}
	return 0;
}
