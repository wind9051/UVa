/*
 * Problem: "UVa 297 - Quadtrees"
 *  Author: "Jia_coding"
 * 
 *     Tag: 樹 DFS 分治
**/

#include <bits/stdc++.h>
using namespace std;

int idx;
string s;
vector<vector<bool>> canvas;

/*
 * x, y  : 左上角座標
 * size  : 區塊邊長
 */
void draw(int x, int y, int size) {
    char c = s[idx++];

    if (c == 'f') {
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                canvas[i][j] = true;
            }
        }
    }
    if (c == 'p') {
        int half = size / 2;
        draw(x,         y,         half); // 左上
        draw(x,         y + half,  half); // 右上
        draw(x + half,  y,         half); // 左下
        draw(x + half,  y + half,  half); // 右下
    }
    if (c == 'e') {
        //pass
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        canvas.assign(32, vector<bool>(32, false));

        cin >> s;
        idx = 0;
        draw(0, 0, 32);

        cin >> s;
        idx = 0;
        draw(0, 0, 32);

        int black = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                if (canvas[i][j]) black++;
            }
        }
        printf("There are %d black pixels.\n", black);
    }
    return 0;
}
