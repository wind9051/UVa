/*
 * Problem: "UVa 598 - Bundling Newspapers"
 *  Author: "Jia_coding"
 * 
 *     Tag: DFS(回溯)
**/

#include <bits/stdc++.h>
using namespace std;

int target;
vector<string> news, cur;
void dfs(int idx) {
    if (cur.size() == target) {
        for (int i = 0; i < cur.size(); i++) {
            cout << cur[i];
            if (i + 1 < cur.size()) cout << ", ";
        }
        cout << endl;
        return;
    }

    for (int i = idx; i < news.size(); i++) {
        cur.push_back(news[i]);
        dfs(i + 1);
        cur.pop_back();
    }
}


int main() {
    int t;
    cin >> t;
    cin.get();
    cin.get();
    while (t--) {
        string s;
        getline(cin, s);
        
        string s1;
        news.clear();
        while (getline(cin, s1) && s1.size()) {
            news.push_back(s1);
        }
        
        int a, b, l = news.size();
        if (s == "*") {
            a = 1; b = l;
        }
        else {
            stringstream ss(s);
            ss >> a >> b;
            if (ss.fail()) {
                b = a;
            }
        }
    
        for (int i = a; i <= b; i++) {
            cout << "Size " << i << endl;
            target = i;
            cur.clear();
            dfs(0);
            cout << endl;
        }
        if (t) cout << endl;
    }

    return 0;
}
