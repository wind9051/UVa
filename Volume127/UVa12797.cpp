/*
 * Problem: "UVa 12797 - Letters"
 *  Author: "Jia_coding"
 * 
 *     Tag: 位元遮罩 BFS
**/

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {

    int N;
    while (cin >> N) {
        vector<string> g(N);
        for (int i = 0; i < N; i++) cin >> g[i];

        int ans = INT_MAX;
        for (int mask = 0; mask < (1 << 10); mask++) {

            char ch = g[0][0];
            int idx = tolower(ch) - 'a';

            if (islower(ch)) {
                if (mask & (1 << idx)) continue;
            } 
            else {
                if (!(mask & (1 << idx))) continue;
            }

            // BFS
            vector<vector<int>> dist(N, vector<int>(N, -1));
            queue<pair<int,int>> q;

            dist[0][0] = 1;
            q.push({0, 0});

            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if (dist[nx][ny] != -1) continue;

                    char c = g[nx][ny];
                    int id = tolower(c) - 'a';

                    if (islower(c)) {
                        if (mask & (1 << id)) continue;
                    } 
                    else {
                        if (!(mask & (1 << id))) continue;
                    }

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }

            if (dist[N-1][N-1] != -1) {
                ans = min(ans, dist[N-1][N-1]);
            }
        }

        if (ans == INT_MAX) cout << -1 << '\n';
        else cout << ans << '\n';
    }

    return 0;
}