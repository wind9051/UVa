/*
 * Problem: "UVa 10142 - Australian Voting"
 *  Author: "Jia_coding"
 * 
 *     Tag: 模擬(Simulation)       
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<string> candidates(n);
        for (int i = 0; i < n; i++) {
            getline(cin, candidates[i]);
        }

        string line;
        vector<vector<int>> ballots;
        while (getline(cin, line) && line.size()) {
            stringstream ss(line);
            vector<int> vote(n);
            for (int i = 0; i < n; i++) {
                ss >> vote[i];
                vote[i]--;
            }
            ballots.push_back(vote);
        }

        vector<bool> eliminated(n, false);

        while (true) {

            vector<int> votes(n, 0);

            // 計票
            for (auto &b : ballots) {
                for (int i = 0; i < n; i++) {
                    if (!eliminated[b[i]]) {
                        votes[b[i]]++;
                        break;
                    }
                }
            }

            int maxVote = 0, minVote = INT_MAX;

            for (int i = 0; i < n; i++) {
                if (!eliminated[i]) {
                    maxVote = max(maxVote, votes[i]);
                    minVote = min(minVote, votes[i]);
                }
            }

            // 過半勝出
            if (maxVote * 2 > ballots.size()) {
                for (int i = 0; i < n; i++) {
                    if (!eliminated[i] && votes[i] == maxVote) {
                        cout << candidates[i] << "\n";
                    }
                }
                break;
            }

            // 平手
            if (maxVote == minVote) {
                for (int i = 0; i < n; i++) {
                    if (!eliminated[i]) {
                        cout << candidates[i] << "\n";
                    }
                }
                break;
            }

            // 淘汰最低票
            for (int i = 0; i < n; i++) {
                if (!eliminated[i] && votes[i] == minVote) {
                    eliminated[i] = true;
                }
            }
        }

        if (T) cout << "\n";
    }

    return 0;
}