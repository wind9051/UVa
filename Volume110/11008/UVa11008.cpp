/*
 * Problem:  "UVa11008 - Antimatter Ray Clearcutting"
 *  Author: "Jia_coding"
 * 
 *     Tag: DP(動態規劃), Bitmask(位元遮罩), (共線)
**/

#include <iostream>
#include <algorithm>
using namespace std;

struct Tree {
    int x, y;
} trees[20];

int n, m;

//三點共線ABC
//(y2-y1)/(x2-x1) == (y3-y1)/(x3-x1)
//(y2-y1)*(x3-x1) == (y3-y1)*(x2-x1)
bool judge(int i, int j, int k) {
    int a = (trees[j].y - trees[i].y) * (trees[k].x - trees[i].x);
    int b = (trees[k].y - trees[i].y) * (trees[j].x - trees[i].x);
    return a == b;
}

int  G[20][20], DP[1<<20];
void init() {
    // 初始化G[i][j]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            G[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (judge (i, j, k)) {
                    // G[i][j] = (1 << k) 代表k在直線ij上
					G[i][j] |= (1 << k); 
                }
            }
        }
    }
    for (int i = 0; i <= (1<<n); i++) DP[i] = 20;
}

int count (int S) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
        if ((1<<i) & S)	ans++;
    }
	return ans;
}

int DFS(int S) {
    // S 代表狀態 1010 表示第4和第2棵樹

    //ans 最小砍樹數量
    int& ans = DP[S];

    if (DP[S] != 20) return ans;

    if (count(S) >= m) return ans = 0;

    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (((1 << i) & S) == 0) {
            for (int j = i+1; j < n; j++) {
                if (((1 << j) & S) == 0) {
                    flag = 1;
                    // S | G[i][j] 代表砍掉i和j之後，剩下的樹
                    ans = min(ans, DFS(S | G[i][j]) + 1);
                }
                if (!flag) {
                    // S | (1 << i) 代表砍掉i之後，剩下的樹
                    ans = min(ans, DFS(S | (1 << i)) + 1);
                }
            }
        }
    }
    return ans;
}

int main () {
    int t, Case = 1;
    cin >> t;
    while (t--) {
        
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> trees[i].x >> trees[i].y;
        }

        init();
        

        printf("Case #%d:\n", Case++);
        printf("%d\n", DFS(0));

        if (t) printf("\n");
    }
    return 0;
}
