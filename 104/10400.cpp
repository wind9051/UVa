/*
 * Title:  "UVa10400 - Game Show Math"
 * Author: "Jia_coding"
 * Date:   "2024/08/15"
 */

#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 32000;
    
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, e;
        cin >> n;
        vector<int> Num(n);
        for (int i = 0; i < n; i++) cin >> Num[i];
        
        cin >> e;

        vector<vector<int>> DP(110, vector<int>(64010, 0));
        vector<vector<vector<int>>> Track(110, vector<vector<int>>(64010, vector<int>(2)));

        DP[0][Num[0] + OFFSET] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= 64000; j++)
            {
                if (DP[i - 1][j])
                {
                    int now = j - OFFSET;
                    if (abs(now + Num[i]) < OFFSET) 
                    {
                        DP[i][now + Num[i] + OFFSET] = 1;
                        Track[i][now + Num[i] + OFFSET][0] = 0;
                        Track[i][now + Num[i] + OFFSET][1] = j;
                    }
                    if (abs(now - Num[i]) < OFFSET)
                    {
                        DP[i][now - Num[i] + OFFSET] = 1;
                        Track[i][now - Num[i] + OFFSET][0] = 1;
                        Track[i][now - Num[i] + OFFSET][1] = j;
                    }
                    if (abs(now * Num[i]) < OFFSET)
                    {
                        DP[i][now * Num[i] + OFFSET] = 1;
                        Track[i][now * Num[i] + OFFSET][0] = 2;
                        Track[i][now * Num[i] + OFFSET][1] = j;
                    }
                    if (!(now % Num[i]) && abs(now / Num[i]) < OFFSET)
                    {
                        DP[i][now / Num[i] + OFFSET] = 1;
                        Track[i][now / Num[i] + OFFSET][0] = 3;
                        Track[i][now / Num[i] + OFFSET][1] = j;
                    }
                }
            }
        }

        if (DP[n - 1][e + OFFSET])
        {
            string op = "+-*/";
            
            vector<char> ops;
            for (int i = n - 1, j = e + OFFSET; i >= 1; i--)
            {
                ops.insert(ops.begin(), op[Track[i][j][0]]);
                j = Track[i][j][1];
            }
            for (int i = 0; i < n; i++)
            {
                cout << Num[i];
                
                if (i < n - 1) cout << ops[i];
            }
            printf("=%d\n", e);
        }
        else cout << "NO EXPRESSION\n";
    }

    return 0;
}
