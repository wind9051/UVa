/*
 * Problem: "UVa 118 - Mutant Flatworld Expolrers"
 *  GitHub: "https://github.com/wind9051/UVa"
 *  Notion: "https://titanium-cylinder-f1d.notion.site/00118-271d4158fd1580c89212fd1516b074ec?source=copy_link"
 *  Author: "Jia_coding"
 * 
 *     Tag: 棋盤 - 網格
**/

#include <bits/stdc++.h>
using namespace std;

char d;
int R, C, X, Y;
string instruction;

int dx[4] = {0, 1, 0, -1};//N E S W
int dy[4] = {1, 0, -1, 0};

map <char, int> ctoi;
map <int, char> itoc;
void initKey() {
    ctoi['N'] = 0; itoc[0] = 'N';
    ctoi['E'] = 1; itoc[1] = 'E';
    ctoi['S'] = 2; itoc[2] = 'S';
    ctoi['W'] = 3; itoc[3] = 'W';
}

bool inGrid(int x, int y) {
    return (0 <= x) && (x <= R) && (0 <= y) && (y <= C);
}

int main() {
    initKey();	
	
	  bool lost = 1;
	  cin >> R >> C;
	  vector<vector<bool>> G(R+1, vector<bool>(C+1, 0));
    while (cin >> X >> Y >> d) {
        cin >> instruction;

        lost = 0;
        int nowd = ctoi[d];
        for (char ch : instruction) {
            if (ch == 'R') {
                nowd = (nowd + 1) % 4;
            }
            if (ch == 'L') {
                nowd = (nowd + 4 - 1) % 4;
            }
            if (ch == 'F') {
                int nx = X + dx[nowd];
                int ny = Y + dy[nowd];
                if (inGrid(nx, ny)) {
                    X = nx;
                    Y = ny;
                }
                else {
                    if (G[X][Y]) continue;
                    else {
                        lost = 1;
                        G[X][Y] = 1;
                        break;
                    }
                }
            }
        }
        printf("%d %d %c", X, Y, itoc[nowd]);
        if (lost) printf(" LOST");
        
        printf("\n");
    }	  
	  return 0;
}
