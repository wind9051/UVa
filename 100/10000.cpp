/*
 * Title:  "UVa10000 - Longest Paths"
 * Author: "Jia_coding"
 * Date:   "2024/08/15"
 */

#include <bits/stdc++.h>
using namespace std;

int main () 
{
    int n, s, Case = 0;
    while (cin >> n && n) 
    {
        cin >> s;
        
        int x, y;
        vector<vector<int>> M(n+1, vector<int>(n+1, 0));
        while (cin >> x >> y && x != 0 && y != 0) 
        {
            M[x][y] = 1;
        }
        
        /*
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < n+1; j++) {
                cout << M[i][j]<<" ";
            }
            cout<<endl;
        }
        */

        //SPFA
        queue<int> Q;
        vector<int> V(n+1, 0);
        vector<int> L(n+1, 0);
        Q.push(s); V[s] = 1;
        while (!Q.empty()) 
        {
            int now = Q.front(); Q.pop();
            V[now] = 0;
            for (int i = 1; i <= n; i++) 
            {
                if (M[now][i] == 1 && L[now] + 1 > L[i]) 
                {
                    L[i] = L[now] + 1;
                    if (V[i] == 0) 
                    {
                        Q.push(i), V[i] = 1;
                    }
                }
                  
            }
            //for (int x : V) cout<<x<<" "; cout<<endl;
            //for (int x : L) cout<<x<<" "; cout<<endl; 
        }
        int maxl = 0, e = 0;
        for (int i = 1; i <= n; i++) 
        {
            if (L[i] > maxl) 
            {
                maxl = L[i], e = i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++Case, s, maxl, e);
    }
    return 0;
}
