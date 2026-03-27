/*
 * Problem: "UVa 929 - Number Maze"
 *  Author: "Jia_coding"
 * 
 *     Tag: BFS, PQ
**/

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct Step{
    int x, y, deep;

    bool operator<(const Step& other) const {
        return deep > other.deep;
    }
};

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> maze(N, vector<int>(M));
        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                cin >> maze[i][j];
            }
        }
            
        vector<vector<int>> dist(N, vector<int>(M, INT_MAX));

        priority_queue<Step> pq;

        dist[0][0] = maze[0][0];
        pq.push({0, 0, maze[0][0]});

        while(!pq.empty()){
            Step cur = pq.top(); pq.pop();

            int x = cur.x;
            int y = cur.y;
            int cost = cur.deep;

            if (cost > dist[x][y]) continue;

            for (int i = 0; i < 4; i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                int newCost = cost + maze[nx][ny];

                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({nx, ny, newCost});
                }
            }
        }

        cout << dist[N-1][M-1] << "\n";
    }
}