/*
 * Title:  "UVa10102 - The path in the colored field"
 * Author: "Jia_coding"
 * Date:   "2024/08/16"
 */

#include <bits/stdc++.h>
using namespace std;

int main () {
    int M;
    while (cin >> M) {
        set<vector<int>> hash1;
        set<vector<int>> hash3;
        for (int i = 0; i < M; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < M; j++) {
                if (s[j] == '1') hash1.insert({i,j});
                if (s[j] == '3') hash3.insert({i,j});
            }
        }
        
        //for (auto v : hash1) cout<<v[0]<<" "<<v[1]<<endl;
        //for (auto v : hash3) cout<<v[0]<<" "<<v[1]<<endl;
        
        int maxn = 0; 
        for (auto v1 : hash1) {
            int minn = 1e5;
            int x1 = v1[0], y1 = v1[1];
            for (auto v2 : hash3) {
                int x2 = v2[0], y2 = v2[1];
                minn = min(minn, abs(x2 - x1) + abs(y2 - y1));
            }    
            maxn = max(maxn, minn);
        }
        cout<<maxn<<endl;

    }
    return 0;
}
