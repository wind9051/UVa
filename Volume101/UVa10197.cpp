/*
 * Problem: "UVa 10197 - Learning Portuguese"
 *  Author: "Jia_coding"
 * 
 *     Tag: 字串(String), 模擬(Simulation)
**/

#include <bits/stdc++.h>
using namespace std;

const string NOS = "n" + string(1, 243) + 's';
const string VOS = "v" + string(1, 243) + 's';

int getCategory(string &v) {
	int len = v.size();
    if (len < 2 || v.back() != 'r') return 0;
    if (v[len-2] == 'a') return 1;
    if (v[len-2] == 'e') return 2;
    if (v[len-2] == 'i') return 3;
    return 0;
}

int main ()
{
    int Case = 0;
    string v1, v2;
    while (cin >> v1 >> v2) {
        if (Case++) printf("\n");

        cout << v1 << " (to " << v2 << ")\n";
        
		int category = getCategory(v1);
        if (category == 0) {
            printf("Unknown conjugation\n");
            continue;
        }

        string root = v1.substr(0, v1.size()-2);
        if (category == 1) {
            printf("%-10s%s%s\n", "eu", root.c_str(), "o");
            printf("%-10s%s%s\n", "tu", root.c_str(), "as");
            printf("%-10s%s%s\n", "ele/ela", root.c_str(), "a");
            printf("%-10s%s%s\n", NOS.c_str(), root.c_str(), "amos");
            printf("%-10s%s%s\n", VOS.c_str(), root.c_str(), "ais");
            printf("%-10s%s%s\n", "eles/elas", root.c_str(), "am");
            
            //cout << left << setw(10) << "eu" << root << "o\n";
        }
        else if (category == 2) {
            printf("%-10s%s%s\n", "eu", root.c_str(), "o");
            printf("%-10s%s%s\n", "tu", root.c_str(), "es");
            printf("%-10s%s%s\n", "ele/ela", root.c_str(), "e");
            printf("%-10s%s%s\n", NOS.c_str(), root.c_str(), "emos");
            printf("%-10s%s%s\n", VOS.c_str(), root.c_str(), "eis");
            printf("%-10s%s%s\n", "eles/elas", root.c_str(), "em");
        }
        else {
            printf("%-10s%s%s\n", "eu", root.c_str(), "o");
            printf("%-10s%s%s\n", "tu", root.c_str(), "es");
            printf("%-10s%s%s\n", "ele/ela", root.c_str(), "e");
            printf("%-10s%s%s\n", NOS.c_str(), root.c_str(), "imos");
            printf("%-10s%s%s\n", VOS.c_str(), root.c_str(), "is");
            printf("%-10s%s%s\n", "eles/elas", root.c_str(), "em");
        }
    }
    return 0;
}