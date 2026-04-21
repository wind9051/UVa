/*
 * Problem: "UVa 10134 - AutoFish"
 *  Author: "Jia_coding"
 * 
 *     Tag: 模擬
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.get();
    cin.get();
    while (t--) {
        string s;
        int F = 0, cnt = 1, fish = 0;
        int bait = 0, rest = 0, sum = 0;
        while (getline(cin, s) && s.size()) {
            if (s == "fish") {
                if (bait >= 2 && (!sum || (fish >= 2 && rest >= 7))) {
                    bait-=2, fish = 0, rest = 0, sum++;
                }
                else fish++;
            }
            
            if (s == "bait" && bait < 6) bait++;
            
            rest++;
        }  
        printf("%d\n", sum);
        
        if (t) printf("\n");
    }
    return 0;
}