/*
 * Problem: "UVa 12791 - Lap"
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;  
    while (cin >> x >> y) {
        double laps = (double)x / (y - x) + 1;
        cout << ceil(laps) << endl;
    }
    return 0;
}
