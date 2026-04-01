/*
 * Problem: "UVa 10127 - Ones"
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學, 餘數(MOD)
**/

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (cin >> n) {
        int bit = 1, sum = 1;
        while (sum % n != 0) {
            //sum = (sum_1 *10 + 1) MOD n
            sum = (sum * 10 + 1) % n;
            bit++;
        }
        cout<<bit<<endl;
    }
    return 0;
}