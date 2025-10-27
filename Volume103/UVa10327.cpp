/*
 * Title:  "UVa 10327 - Flip Sort"
 * Author: "Jia_coding"
 *   
 *    tag: 排序(Sorting), 冒泡排序(Bubble Sort)
**/

#include <vector>
#include <iostream>
using namespace std;

int N;

int main () {
	while (cin >> N) {
		vector<int> Num(N);
		for (int i = 0; i < N; i++) {
			cin >> Num[i];
		}

		int cnt = 0; //exchanges;

		//Bubble Sort
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N-1 - i; j++) {
				if (Num[j] > Num[j+1]) {
					cnt++;
					swap(Num[j], Num[j+1]);
				}
			}
		}
		printf("Minimum exchange operations : %d\n", cnt);
	}
	return 0;
}