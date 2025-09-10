/*
 * Problem: "UVa 10107 - What is the Median"
 *  Author: "Jia_coding"
 * 
 *     Tag: 中位數(Median)
**/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main () {
    ll n;
    vector<ll> num;
    while (cin >> n) {
        num.push_back(n);
        sort(num.begin(), num.end());
        
        int len = num.size();
        if (len%2) cout << num[len/2] <<endl;
        else cout << (num[len/2-1] + num[len/2]) / 2 << endl; 
    }
    return 0;
}