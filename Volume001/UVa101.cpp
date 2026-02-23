/*
 * Problem: "UVa 101 - The Blocks Problem"
 *  Author: "Jia_coding"
 * 
 *     Tag: vector
**/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n;
vector<vector<int>> P; //piles

pii find_pos(int x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < P[i].size(); j++) {
            if (P[i][j] == x) return {i, j};
        }
    }
}

void clear_above(int p, int h){
    while (P[p].size() > h+1) {
        int x = P[p].back();
        P[p].pop_back();
        P[x].push_back(x);
    }
}

void move_onto(int a, int b) {
    auto [pa, ha] = find_pos(a);
    auto [pb, hb] = find_pos(b);
    if (pa == pb) return;

    clear_above(pa, ha);
    clear_above(pb, hb);

    P[pa].pop_back();
    P[pb].push_back(a);
}

void move_over(int a, int b){
    auto [pa, ha] = find_pos(a);
    auto [pb, hb] = find_pos(b);
    if(pa == pb) return;

    clear_above(pa, ha);

    P[pa].pop_back();
    P[pb].push_back(a);
}

void pile_onto(int a, int b){
    auto [pa, ha] = find_pos(a);
    auto [pb, hb] = find_pos(b);
    if(pa == pb) return;

    clear_above(pb, hb);
    
    vector<int> v;
    for (int i = ha; i < P[pa].size(); i++) {
        v.push_back(P[pa][i]);
    }
    P[pa].resize(ha);
    
    for (int x : v) P[pb].push_back(x);
}

void pile_over(int a, int b){
    auto [pa, ha] = find_pos(a);
    auto [pb, hb] = find_pos(b);
    if(pa == pb) return;

    vector<int> v;
    for (int i = ha; i < P[pa].size(); i++) {
        v.push_back(P[pa][i]);
    }
    P[pa].resize(ha);
    
    for (int x : v) P[pb].push_back(x);
}

int main() {
    while (cin >> n) {
        P.assign(n, vector<int>());
        for (int i = 0; i < n; i++) P[i].push_back(i);
        
        int p1, p2;
        string s1, s2;
        while (cin >> s1 && s1 != "quit") {
            cin >> p1 >> s2 >> p2;
            
            if (s1 == "move" && s2 == "onto") move_onto(p1, p2);
            else if (s1 == "move" && s2 == "over") move_over(p1, p2);
            else if (s1 == "pile" && s2 == "onto") pile_onto(p1, p2);
            else if (s1 == "pile" && s2 == "over") pile_over(p1, p2);
        }
        
        for (int i = 0; i < n; i++) {
            cout << i << ":";
            for (int x: P[i]) cout << " " << x;
            cout << "\n";
        }
    }
    return 0;
}