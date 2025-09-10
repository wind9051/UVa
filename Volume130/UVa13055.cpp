/*
 * Problem: "UVa 13055 - Inception"
 *  Author: "Jia_coding"
 * 
 *     Tag: stack(堆疊)
 * 
**/

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (cin >> n) {
        stack<string> Dream;
        for (int i = 0; i < n; i++) {
            string op;
            cin >> op;
            
            if (op == "Sleep") { 
                string name;
                cin >> name;
                Dream.push(name);
            }
            if (op == "Kick") {
                if (!Dream.empty()) Dream.pop();
            }
            if (op == "Test") {
                if (!Dream.empty()) printf("%s\n", Dream.top().c_str());
                else printf("Not in a dream\n");
            }
            
        }
    }
    return 0;
}