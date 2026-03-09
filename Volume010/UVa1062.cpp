/*
 * Problem: "UVa 1062 - Containers"
 *  Author: "Jia_coding"
 * 
 *     Tag: 堆疊, DP - LIS
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int Case = 1;
    string line;
    while (cin >> line && line != "end") {
        
        //LIS
        vector<int> Heap;
        for (auto c : line) {
            auto it = lower_bound(Heap.begin(), Heap.end(), c);
            if (it == Heap.end()) Heap.push_back(c);
            else *it = c;
        }
        printf("Case %d: %d\n", Case++, Heap.size());
    }
    return 0;
}
