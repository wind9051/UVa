/*
 * Problem: "UVa 103 - Stacking Boxes"
 *  Author: "Jia_coding"
 * 
 *     Tag: DP(LIS)
**/

#include <bits/stdc++.h>
using namespace std;

struct Box {
    int id; 
    vector<int> dim;

    bool operator<(const Box& other) const {
        for (int i = 0; i < dim.size(); i++) {
            if (this->dim[i] < other.dim[i]) return true;
            if (this->dim[i] > other.dim[i]) return false;
        }
        return false;
    }
};


bool can_nest(const Box& a, const Box& b){
    for (int i = 0; i < a.dim.size(); i++) {
        if(a.dim[i] >= b.dim[i]) return false;
    }
    return true;
}

int main(){
    int k, n;
    while(cin >> k >> n){
        vector<Box> boxes(k);

        for (int i = 0; i < k; i++){
            boxes[i].id = i+1;
            boxes[i].dim.resize(n);
            
            for (int j = 0; j < n; j++) cin >> boxes[i].dim[j];
            sort(boxes[i].dim.begin(), boxes[i].dim.end());
        }

        sort(boxes.begin(), boxes.end());

        //LIS
        vector<int> DP(k, 1), pre(k,-1);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < i; j++) {
                if (can_nest(boxes[j], boxes[i]) && DP[j]+1 > DP[i]){
                    DP[i] = DP[j]+1;
                    pre[i] = j;
                }
            }
        }

        int best = 0, idx = 0;
        for (int i = 0; i < k; i++) {
            if(DP[i] > best){
                best = DP[i];
                idx = i;
            }
        }

        vector<int> path;
        while(idx != -1){
            path.push_back(boxes[idx].id);
            idx = pre[idx];
        }
        reverse(path.begin(), path.end());

        cout << best << "\n";
        for(int i = 0; i < path.size(); i++) {
            if (i) cout << " ";
            cout << path[i];
        }
        cout << "\n";
    }
}
