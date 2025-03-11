#include<bits/stdc++.h>
using namespace std;

int ans=0;
set<string> S;

int getMaxHandScore(int p, vector<pair<int, char>> &in){
    int ret = 0;
    for (int i = 0; i < (1<<p); i++) {
        string tmp = "";
        int score = 0;
        for (int j = 0; j < p; j++) {
            if ((i & (1<<j))) {
                score += in[j].first;
                tmp += string(1,in[j].second);
            }
        }
        sort(begin(tmp), end(tmp));
        
        if (S.find(tmp) != S.end()) ret = max(ret, score);
    }
    return ret;
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        sort(begin(tmp), end(tmp));
        S.insert(tmp);
    }
    
    int T;
    cin >> T;
    while (T--) {
        int p;
        cin >> p;
        vector<pair<int, char>> in(p);
        for (int i = 0; i < p; i++) {
            cin >> in[i].second >> in[i].first;
        }

        ans=0;
        cout << getMaxHandScore(p, in) << endl;
    }
    return 0;
}
