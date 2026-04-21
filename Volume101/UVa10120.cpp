/*
 * Problem: "UVa 10120 - Gift?!"
 *  Author: "Jia_coding"
 *
 *     Tag: 數學(Math), DFS(深度優先搜尋)
 *          數論(Number Theory)
 *
**/

#include <bits/stdc++.h>
using namespace std;

int N, M;

//shift = 2 * level - 1;
bool DFS(int cur, int shift) {
    if (cur == M) return true;
    
    if (cur < 1 || cur > N) return false;
    //cout<<cur<<" "<<shift<<endl;
    
    if (DFS(cur+shift, shift+2)) return true;
    if (DFS(cur-shift, shift+2)) return true;
    
    return false;
}

int main () {
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;
        bool flag = N > 48 || DFS(1, 3);
        if (flag) printf("Let me try!\n");
        else printf("Don't make fun of me!\n");
    }
    return 0;
}
