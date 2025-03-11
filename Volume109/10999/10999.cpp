#include<bits/stdc++.h>
using namespace std;

int ans=0;
set<string> S;

int getMaxHandScore(int letterCnt, vector<pair<char, int>> &letters){
    int ret = 0;
    //位運算枚舉子集
    for (int mask = 0; mask < (1<<letterCnt); mask++) {
        string tmp = "";
        int score = 0;
        for (int bit = 0; bit < letterCnt; bit++) {
            if (mask & (1<<bit)) {
                tmp += letters[bit].first;
                score += letters[bit].second;
            }
        }
        
        if (S.count(tmp)) ret = max(ret, score);
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
        int letterCnt;
        cin >> letterCnt;
        vector<pair<char, int>> letters(letterCnt);
        for (int i = 0; i < letterCnt; i++) {
            cin >> letters[i].first >> letters[i].second;
        }
        sort(begin(letters), end(letters));

        ans = 0;
        cout << getMaxHandScore(letterCnt, letters) << endl;
    }
    return 0;
}
