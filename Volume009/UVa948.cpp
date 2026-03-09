/*
 * Problem: "UVa 948 - Fibonaccimal Base"
 *  Author: "Jia_coding"
 * 
 *     Tag: DP(Fib)
**/

#include<bits/stdc++.h>
using namespace std;

vector<int> initFib() {
    vector<int> fib(45);
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= 40; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib;
}	

int main() {
    vector<int> fib = initFib();

    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        cout << n << " = ";
        
        int R = 40;
        while (n < fib[R]) R--;

        while (R >= 1) {
            if (n >= fib[R]) {
                n -= fib[R];
                cout << 1;
            }
            else {
                cout << 0;
            }
            R--;
        }
        cout << " (fib)" << endl;
    }
    return 0;
}
