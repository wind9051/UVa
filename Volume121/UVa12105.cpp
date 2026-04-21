/*
 * Problem: "UVa 12105 - Bigger is Better"
 *  Author: "Jia_coding"
 * 
 *     Tag: DP
**/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int costs[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

string max_str(const string& a, const string& b) {
    if (a == "invalid") return b;
    if (b == "invalid") return a;
    
    // ("111" > "99")
    if (a.size() != b.size()) return a.size() > b.size() ? a : b;
    
    // ("98" > "97")
    return a > b ? a : b;
}

void solve(int n, int m, int caseNum) {
    // dp[i][j] 代表：剛好使用 i 根火柴，且數字除以 m 的餘數為 j 時的最大數字字串
    vector<vector<string>> dp(n + 1, vector<string>(m, "invalid"));
    
    dp[0][0] = "";

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dp[i][j] == "invalid") continue;

            for (int k = 0; k <= 9; ++k) {
                int next_i = i + costs[k]; 
                int next_j = (j * 10 + k) % m; 

                if (next_i <= n) {
                    if (dp[i][j] == "" && k == 0) {
                        dp[next_i][next_j] = "0";
                    } 
                    else if (dp[i][j] != "0") {
                        dp[next_i][next_j] = max_str(dp[next_i][next_j], dp[i][j] + (char)(k + '0'));
                    }
                }
            }
        }
    }

    string ans = "invalid";
    for (int i = 1; i <= n; ++i) {
        ans = max_str(ans, dp[i][0]);
    }

    cout << "Case " << caseNum << ": ";
    if (ans == "invalid") cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    int n, m, caseNum = 1;
    while (cin >> n >> m && (n != 0)) {
        solve(n, m, caseNum++);
    }
    return 0;
}