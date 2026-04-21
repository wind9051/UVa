/*
 * Problem: "UVa 10113 - Exchange Rates"
 *  Author: "Jia_coding"
 * 
 *     Tag: 圖論, DFS, 分數
**/

#include <bits/stdc++.h>
using namespace std;

struct Fraction {
    int num, den; // num / den

    Fraction (int n = 0, int d = 1) {
        int g = __gcd(n, d);
        num = n / g;
        den = d / g;
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(num * other.num, den * other.den);
    }
};

int id_cnt = 0;
map<string, int> item_id;

vector<vector<Fraction>> G(65, vector<Fraction>(65));

bool dfs(int cur, int target, Fraction acc, vector<bool>& visited, Fraction& result) {
    if (cur == target) {
        result = acc;
        return true;
    }

    visited[cur] = true;
    for (int v = 0; v < id_cnt; v++) {
        if (visited[v] || G[cur][v].num == 0) continue;

        if (dfs(v, target, acc * G[cur][v], visited, result)) return true;
    }

    return false;
}

int main() {
    string cmd;
    while (cin >> cmd && cmd != ".") {
        if (cmd == "!") {
            int m, n;
            string a, eq, b;
            cin >> m >> a >> eq >> n >> b;

            if (!item_id.count(a)) {
                item_id[a] = id_cnt++;
            }
            if (!item_id.count(b)) {
                item_id[b] = id_cnt++;
            }

            int u = item_id[a];
            int v = item_id[b];

            // m A = n B
            // A -> (n/m) B
            G[u][v] = {n, m};
            G[v][u] = {m, n};
        }
        else {
            string a, eq, b;
            cin >> a >> eq >> b;

            if (!item_id.count(a) || !item_id.count(b)) {
                cout << "? " << a << " = ? " << b << "\n";
                continue;
            }

            int u = item_id[a];
            int v = item_id[b];

            Fraction result;
            vector<bool> visited(id_cnt, false);

            if (dfs(u, v, Fraction(1, 1), visited, result)) {
                cout << result.den << " " << a << " = " << result.num << " " << b << "\n";
            } 
            else {
                cout << "? " << a << " = ? " << b << "\n";
            }
        }
    }

    return 0;
}