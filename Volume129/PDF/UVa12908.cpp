/*
 * Problem: "UVa 12908 - The book thief"
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學(Math), 等差數列(Arithmetic Progression)
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> num(20000, 0);
    for (int i = 1; i <= 20000; i++) num[i] = num[i-1] + i;
    
    int n;
    while (cin >> n && n) {
        auto L = upper_bound(num.begin(), num.end(), n);
        cout << *L - n << " " << L - num.begin() << endl;
    }
    return 0;
}
