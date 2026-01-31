/*
 * Problem: "UVa 497 - Strategic Defense Initiative "
 *  Author: "Jia_coding"
 * 
 *     Tag: DP-LIS
**/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int T;
    string tmp;
    while(cin >> T){
        cin.ignore();
        cin.ignore(); 

        for(int Case = 0; Case < T; Case++){
            vector<int> arr;
            while(getline(cin, tmp) && !tmp.empty()){
                arr.push_back(stoi(tmp));
            }

            int n = arr.size();
            vector<int> LIS;
            vector<int> tail_idx;
            vector<int> parent(n, -1);

            vector<int> pos(n, 0);

            for (int i = 0; i < n; i++){
                int x = arr[i];
                auto it = lower_bound(LIS.begin(), LIS.end(), x);
                int idx = it - LIS.begin();

                if (it == LIS.end()){
                    LIS.push_back(x);
                    tail_idx.push_back(i);
                } 
                else {
                    *it = x;
                    tail_idx[idx] = i;
                }

                pos[i] = idx;

                if (idx > 0) {
                    parent[i] = tail_idx[idx-1];
                }
            }

            int last = -1;
            for (int i = n-1; i >= 0; i--){
                if (pos[i] == LIS.size() - 1){
                    last = i;
                    break;
                }
            }

            vector<int> LISseq;
            while(last != -1){
                LISseq.push_back(arr[last]);
                last = parent[last];
            }
            reverse(LISseq.begin(), LISseq.end());

            if(Case) cout << "\n";
            cout << "Max hits: " << LIS.size() << "\n";
            for(int x : LISseq) cout << x << "\n";
        }
    }

    return 0;
}
