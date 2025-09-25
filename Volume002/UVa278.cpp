/*
 * Problem: "UVa 278 - Chess"
 *  GitHub: "https://github.com/wind9051/UVa"
 *  Notion: "https://titanium-cylinder-f1d.notion.site/00278-278d4158fd1580a0b536cf7f399cb6c7?source=copy_link"
 *  Author: "Jia_coding"
 * 
 *     Tag: 棋盤 - 西洋棋
**/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        char C;
        int M, N;  
        cin >> C >> M >> N;
        
        int sum = 0;
        if (C == 'K') sum = ((M+1)/2) * ((N+1)/2);
        if (C == 'r') sum = min(M, N);
        if (C == 'Q') sum = min(M, N);
        if (C == 'k') sum = (M*N+1)/2;
        
        printf("%d\n", sum);
    }
    return 0;
}