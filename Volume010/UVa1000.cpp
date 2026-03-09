#include<bits/stdc++.h>
using namespace std;

struct Cost {
    int idx, sum;
    
    Cost(int _id, int _sum) : idx(_id), sum(_sum) {}

    bool operator<(const Cost& other) const {
        if (sum == other.sum) return idx < other.idx;
        return sum < other.sum;
    }
};

int main() {
    int N;
    while (cin >> N && N) {
        int u, v, w, k; 
        vector<vector<int>> G(N+1, vector<int>(N+1, 0));
        for (int i = 0; i < N; i++) {
            cin >> u >> k;
            for (int j = 0; j < k; j++) {
                cin >> v >> w;
                G[u][v] += w;
            }
        }
        
        int N1;
        vector<Cost> configuration;
        while (cin >> N1 && N1) {
            int x;
            vector<int> Sd(N+1, 0), Ed(N+1, 0);
            for (int i = 0; i < N; i++) {
                cin >> x;
                Sd[x] = i;
            }
            for (int i = 0; i < N; i++) {
                cin >> x;
                Ed[x] = i;
            }
            
            int sum = 0;
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    int u = Sd[i];
                    int v = Ed[j];
                    
                    if (G[i][j]) 
                        sum += G[i][j] * (abs(v - u) + 1);
                }
            }
            configuration.emplace_back(N1, sum);
        }

        sort(configuration.begin(), configuration.end());

        printf("Configuration Load\n");
        for (int i = 0; i < configuration.size(); i++) {
            printf("%5d         %d\n", configuration[i].idx, configuration[i].sum);
        }           
    }
    return 0;
}