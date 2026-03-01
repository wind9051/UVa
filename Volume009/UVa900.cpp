/*
 * Problem: "UVa 900 - Brick Wall Patterns"
 *  Author: "Jia_coding"
 * 
 *     Tag: DP - Fib
**/

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> fnc() {
    vector<LL> Fib(55, 0);
    Fib[1] = 1;
    Fib[2] = 2;
    for (int i = 3; i <= 50; i++){
        Fib[i] = Fib[i-1] + Fib[i-2];
    }
    return Fib;
}

int main() {
    vector<LL> Fib = fnc();

    int n;
    while (cin >> n && n != 0){
        cout << Fib[n] << endl;
    }
    return 0;
}