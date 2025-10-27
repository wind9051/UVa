/*
 * Problem:  "UVa 11003 - Boxes"
 *  Author: "Jia_coding"
 * 
 *     Tag: DP(動態規劃), Greedy(貪婪), (背包)
**/

#include <iostream>
using namespace std;

int n;

struct Box {
    int w, c;
} boxes[1005];

int DP[1005][3005];
//DP[i][c] = 第i個箱子、剩餘承重capacity，最多可以堆幾個箱子
void init () {
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 3000; j++) {
            DP[i][j] = -1;
        }
    }
    return;
}

int rec (int capacity, int i) {
	if (i == n || !capacity) return 0;

	int & memo = DP[i][capacity];
	if (memo != -1) return memo;

    // 如果第i個箱子可以放進去
    // 那麼有兩種選擇：放進去或不放進去
	if (boxes[i].w <= capacity) {
		return memo = max(rec(min(capacity - boxes[i].w, boxes[i].c), i + 1) + 1, rec(capacity, i + 1));
    }  
    // 如果第i個箱子不能放進去
    // 那麼只能選擇不放進去
	else {
        return memo = rec(capacity, i + 1);
    }
}


int main () {
    
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> boxes[i].w >> boxes[i].c;
        }

        init();

        int lmax = -1;
        for (int i = 0; i < n; i++) {
            lmax = max(lmax, rec(boxes[i].c, i+1)+1);
        }
        cout << lmax << endl;
    }
    return 0;
}