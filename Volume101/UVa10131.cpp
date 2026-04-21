/*
 * Problem: "UVa 10131 - Is Bigger Smarter?"
 *  Author: "Jia_coding"
 * 
 *     Tag: 動態規劃(DP), 最長遞增子序列(LIS)
**/

#include <bits/stdc++.h>
using namespace std;
 
struct Animal {
    int W, IQ, id;

    bool operator< (const Animal & other) const {
        if (W == other.W) return IQ > other.IQ;
        return W < other.W;
    }
};
 
int main() {
    vector<Animal> N;
    int cnt = 0;
    Animal now;
    while (cin >> now.W >> now.IQ) {
        now.id = ++cnt;
        N.push_back(now);
    }
    sort(N.begin(), N.end());
    
    //LIS
    int best_len = 0, best_idx = 0; 
    vector<int> DP(1005, 1), pre(cnt, -1);
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < i; j++) {
            if (N[i].W > N[j].W && N[i].IQ < N[j].IQ) {
                if (DP[i] < DP[j]+1) {
                    DP[i] = DP[j]+1;
                    pre[i] = j;
                }
            }
        }
        if (DP[i] > best_len) {
            best_len = DP[i];
            best_idx = i;
        }
    }
    
    vector<int> ans;
    int cur = best_idx;
    while (cur != -1) {
        ans.push_back(N[cur].id);
        cur = pre[cur];
    }
    reverse(ans.begin(), ans.end());

    printf("%d\n", best_len);   
    
    for (int id : ans) cout << id << endl;
    
    return 0;
}