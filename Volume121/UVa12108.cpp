/*
 * Problem: "UVa 12108 - Extraordinarily Tired Students"
 *  Notion: ""
 *  Author: "Jia_coding"
 * 
 *     Tag: 哈希 結構
**/

#include<bits/stdc++.h>
using namespace std;

struct People {
    int awake, sleep, curTime, len;
    People(int _a, int _b, int _c)
        : awake(_a), sleep(_b), curTime(_c), len(awake+sleep) {}
};

unordered_set<string> Vis;

int main() {
    int n, Case = 1;
    while (cin >> n && n) {
        vector<People> P;
        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            P.push_back({a, b, c});
        }
        
        for (int Round = 1; Round <= 1e5; Round++) {
            int awake = 0;
            for (auto A : P) {
                if (A.curTime <= A.awake) awake++;
            }
            
            if (awake == n) {
                printf("Case %d: %d\n", Case++, Round);
                break;
            }
            string state = "";
            for (auto &A : P) {
                if (A.curTime == A.len || (A.curTime == A.awake && awake >= n - awake)) A.curTime = 1;
                else A.curTime++;
                state += A.curTime + '0';
            }
            
            if (!Vis.count(state)) Vis.insert(state);
            else {
                printf("Case %d: -1\n", Case++);
                break;
            }
        }
    }

    return 0;
}



