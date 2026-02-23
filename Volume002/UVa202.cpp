/*
 * Problem: "UVa 202 - Repeating Decimals"
 *  Author: "Jia_coding"
 * 
 *     Tag: 浮點數
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        int num = a / b, rem = a % b;
        
        int cycle = 0, start = -1;
        unordered_map<int, int> vis;
        string dem = "";
        while (rem != 0) {
            if (vis.count(rem)) {
                start = vis[rem];
                break;
            }

            vis[rem] = cycle++;

            rem *= 10;
            dem += to_string(rem / b);
            rem %= b;
        }

        cout << a << "/" << b << " = " << num << ".";

        if (rem == 0) {
            cout << dem << "(0)\n";
            cout << "   1 = number of digits in repeating cycle\n\n";
        } 
        else {
            
            cout << dem.substr(0, start);
            cout << "(";
            string cycle_part = dem.substr(start);
            if (cycle_part.size() >= 50) {
                cout << cycle_part.substr(0, 50) << "...";
            } 
            else {
                cout << cycle_part;
            }
            cout << ")\n";

            cout << "   " << cycle_part.size() << " = number of digits in repeating cycle\n\n";
        }
    }
    return 0;
}
