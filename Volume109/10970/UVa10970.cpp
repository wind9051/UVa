/*
 * Problem: "UVa 10970 - Big Chocolate"
 *  Author: "Jia_coding"
 * 
 *     Tag: Math(數學)
 * 
 *    Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1911
**/

#include <iostream>
using namespace std;
int main(){
    int m, n;
    while (cin >> m >> n) {
        cout << (m * n) - 1 << endl;
    }
    return 0;
}
