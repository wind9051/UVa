/*
 * Problem: "UVa 272 - TEX Quotess"
 *  GitHub: "https://github.com/wind9051/UVa"
 *  Notion: "https://titanium-cylinder-f1d.notion.site/00272-278d4158fd1580d48d8befee2ef0fb33?source=copy_link"
 *  Author: "Jia_coding"
 * 
 *     Tag: 字串
**/

#include<iostream>
using namespace std;

int main(){
    string s;
    bool cnt = 1;
    while (getline(cin, s)) {
        for (auto c : s) {
            if (c == '"') {
                if (cnt & 1) printf("``");
                else printf("''");
                cnt ^= 1;
            }
            else printf("%c", c);
        }
        printf("\n");
    }
	  return 0;
}

