/*
 * Problem: "UVa 913 - Joana and the Odd Numbers"
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學
**/

#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    while (cin >> N) {
        ll R = (N+1) / 2;
        
        ll Y = R*R;
        ll X = 2*Y - 1;
        
        //Y + (Y-2) + (Y-4)
        ll sum = 3*X - 6;
        cout << sum << endl;
    }
    return 0;
}