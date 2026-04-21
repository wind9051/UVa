/*
 * Problem: "UVa 10145 - Lock Manager"
 *  Author: "Jia_coding"
 *
 *     Tag: 作業系統(Operating system), 鎖管理(Lock Manager), 
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int MAX = 1e9;

struct Lock {
    char Mode;
    int TRID;
};


int main () {
    int t;
    cin >> t;
    while (t--) {
        set<int> IGNORED;
        map<int, vector<Lock>> ITEM; // ITEM, {MODE, TRID}

        char ch;
        int tr, it;
        while (cin >> ch && ch != '#') {
            cin >> tr >> it;
            
            if (IGNORED.count(tr)) {
                printf("IGNORED\n");
                continue;
            }
            
            if (ITEM.find(it) == ITEM.end()) {
                ITEM[it].push_back({ch, tr});
                printf("GRANTED\n");
                continue;
            }
            else {     
                //conflict
                bool flag = 0;
                int cnt = (ch == 'X');
                for (auto &V : ITEM[it]) {
                    cnt += (V.Mode == 'X');
                    if (V.TRID != tr && cnt >= 1) {
                        IGNORED.insert(tr);
                        printf("DENIED\n");
                        flag = true;
                        break;
                    }
                }
                
                if (!flag) {
                    ITEM[it].push_back({ch, tr});
                    printf("GRANTED\n");
                    continue;  
                }
                
            }
        }

        if (t) printf("\n");
    }
    return 0;
}