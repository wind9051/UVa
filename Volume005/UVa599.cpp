/*
 * Problem: "UVa 599 - The Forrest for the Trees"
 *  Author: "Jia_coding"
 * 
 *     Tag: 並查集
**/

#include<bits/stdc++.h>
using namespace std;

int root[26], Rank[26], vis[26];
void init() {
    for(int i = 0; i < 26; i++) {
        root[i] = i;
        Rank[i] = 1;
        vis[i] = 0;
    }
}

int find_root(int x) {
    if (root[x] == x) return x;
    return root[x] = find_root(root[x]);
}

void Union(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    if (x != y) {
        if (Rank[x] < Rank[y]) swap(x, y);
        Rank[x] += Rank[y];
        root[y] = x;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        
        string s;
        while (cin >> s && s[0] != '*') {
            int u = s[1] - 'A';
            int v = s[3] - 'A';
            
            Union(u, v);
        }
        
        string node;
        cin >> node;
        for (auto &c : node) {
            if (c != ',') vis[c - 'A'] = 1; 
        }
        
        map<int, int> cnt;
        for (int i = 0; i < 26; i++) {
            if (vis[i]) cnt[find_root(i)]++;
        }
        
        int forrest = 0, acorn = 0;
        for (auto [k, v] : cnt) {
            if (v == 1) acorn++;
            else forrest++;
        }
        printf("There are %d tree(s) and %d acorn(s).\n", forrest, acorn);
    }
    return 0;
}