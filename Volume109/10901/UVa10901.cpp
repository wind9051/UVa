/*
 * Title:  "UVa 10901 - Ferry Loading III"
 * Author: "Jia_coding"
 *   
 *    tag: queue(佇列)
**/

#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second

typedef pair<int, int> pii;

int main() {
    int c;
    cin >> c;
    for (int T = 0; T < c; T++) {
        int n, t, m;
        cin >> n >> t >> m;

        queue<pii> Q[2];//L R    
        for (int j = 0; j < m; j++) {
            int arr_time;
            string arr_side;
            cin >> arr_time >> arr_side;
            if (arr_side == "left") Q[0].push({arr_time, j});
            else Q[1].push({arr_time, j});
        }
        
        vector<int> C(m);
        int current_time = 0, mov = 0;
        while (!Q[0].empty() || !Q[1].empty()) {
            int cnt = 0, now_time;
            
            if (Q[0].empty()) now_time = Q[1].front().F;
            else if (Q[1].empty()) now_time = Q[0].front().F;
            else now_time = min(Q[0].front().F, Q[1].front().F);
            
            current_time = max(current_time, now_time);

            while (!Q[mov].empty() && Q[mov].front().F <= current_time && cnt < n) {
                C[Q[mov].front().S] = current_time + t;
                Q[mov].pop();
                cnt++;
            }
            current_time += t;
            mov ^= 1;
        }
        if (T) printf("\n");
        for (auto & i : C) cout << i << "\n";
        
    }

    return 0;
}