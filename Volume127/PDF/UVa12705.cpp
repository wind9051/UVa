/*
 * Problem: "UVa 12705 - Breaking Board"
 *  Author: "Jia_coding"
 * 
 *     Tag: 哈希(Hash), 貪心(Greedy), 排序(Sort)
**/

#include <bits/stdc++.h>
using namespace std;

struct Alpha {
    char key;
    int value;
};

int main () {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        
        map<char, int> Hash;
        for (auto ch : s) {
            if (ch != ' ') Hash[ch]++;
        }
        
        int cnt = 0;
        vector<Alpha> Dic(Hash.size());
        for (auto [u, v] : Hash) {
            Dic[cnt].key = u;
            Dic[cnt++].value = v;
        }
        
        sort(Dic.begin(), Dic.end(), [](Alpha & X, Alpha & Y) {
            return X.value > Y.value;
        });
        
        vector<int> Score(36, 0);
        for (int i = 1; i <= 6; i++) {
            for (int j = 1; j <= 6; j++) {
                Score[(i-1)*6+j-1] = i+j;
            }
        }
        sort(Score.begin(), Score.end());
        
        int sum = 0;
        for (int i = 0; i < Dic.size(); i++) {
            sum += Dic[i].value * Score[i];
        }
        
        printf("%d\n", sum);
    }
    return 0;
}