#include <bits/stdc++.h>
using namespace std;

int main () {
    string ins;
    vector<string> s;
    while (cin >> ins && ins != "#") {
        s.push_back(ins);
    }

    map<char, vector<char>> G;   // adjacency list
    map<char, int> indeg;        // indegree

    for (int i = 0; i < s.size(); i++) {
        for (auto c : s[i]) indeg[c] = 0;
    }

    set<pair<char, char>> VisE; // 用來避免重邊
    for (int i = 0; i < (int)s.size() - 1; i++) {
        string &a = s[i];
        string &b = s[i+1];
        int len = min(a.size(), b.size());
        for (int j = 0; j < len; j++) {
            if (a[j] != b[j]) {
                if (!VisE.count({a[j], b[j]})) {  
                    VisE.insert({a[j], b[j]});
                    G[a[j]].push_back(b[j]);
                    indeg[b[j]]++;
                }
                break;
            }
        }
    }

    // Kahn 拓樸排序
    queue<char> q;
    for (auto &p : indeg) {
        if (p.second == 0) q.push(p.first);
    }

    string ret = "";
    while (!q.empty()) {
        char u = q.front(); q.pop();
        ret += u;
        for (char v : G[u]) {
            if (--indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << ret << endl;
    return 0;
}
