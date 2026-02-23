/*
 * Problem: "UVa 496 - Simply Subsets"
 *  Author: "Jia_coding"
 * 
 *     Tag: 並查集
**/

#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    while (getline(cin, s)) {
        int n;
        set<int> sa, sb;

        stringstream ss(s);
        while (ss >> n) sa.insert(n);

        getline(cin, s);
        stringstream ss2(s);
        while (ss2 >> n) sb.insert(n);


        vector<int> same;
        for (auto x : sa) {
            if (sb.count(x)) {
                same.push_back(x);
            }
        }

        if (!same.size()) {
            printf("A and B are disjoint\n");
            continue;
        }

        for (auto x : same) {
            sa.erase(x);
            sb.erase(x);
        }

        if (sa.empty() && sb.empty()) printf("A equals B\n"); 
        else if (sa.empty()) printf("A is a proper subset of B\n");
        else if (sb.empty()) printf("B is a proper subset of A\n");
        else printf("I'm confused!\n"); 
    }
    return 0;
}