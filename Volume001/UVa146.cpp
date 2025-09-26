/*
 * Problem: "UVa 146 - ID Codes"
 *  Notion: "https://titanium-cylinder-f1d.notion.site/00146-278d4158fd1580da9db8cd349d81e39f?source=copy_link"
 *  Author: "Jia_coding"
 * 
 *     Tag: 排列組合
**/

#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    string s;
    while (cin >> s && s != "#") {
        
        auto it = next_permutation(s.begin(), s.end());

        if (it) cout << s << endl;
        else printf("No Successor\n");
    }
    return 0;
}