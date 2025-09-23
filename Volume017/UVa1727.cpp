/*
 * Problem: "UVa 1727 - Counting Weekend Days"
 *  GitHub: "https://github.com/wind9051/UVa"
 *  Author: "Jia_coding"
 * 
 *     Tag: 日期
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sum;
    cin >> n;
    while (n--) {
        string M, D;
        cin >> M >> D;
        if (M == "FEB") {
            sum = 8;
        } 
        else if (M == "APR" || M == "JUN" || M == "SEP" || M == "NOV") {
            if (D == "FRI") sum = 10;
            else if (D == "THU" || D == "SAT") sum = 9;
            else sum = 8;
        } 
        else {
            if (D == "THU" || D == "FRI") sum = 10;
            else if (D == "SAT" || D == "WED") sum = 9;
            else sum = 8;
        }
        cout << sum << endl;
    }
    return 0;
}