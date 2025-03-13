/*
 * Title:  "UVa10000 - Longest Paths"
 * Author: "Jia_coding"
 * Date:   "2024/08/15"
 */

#include <bits/stdc++.h>
using namespace std;
const int mx = 110;

/*
void print(int c, vector<vector<int>> G) 
{
    for (int i = 1; i <= c; i++) 
    {
        for (int j = 1; j <= c; j++) 
        {
            if (G[i][j] == mx) cout<<"# ";
            else cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
*/

int main () 
{
    int c, s, Case = 1;
    while (cin >> c >> s && c) 
    {
        vector<vector<int>> G(c+1, vector<int>(c+1, mx));
        //for (int i = 1; i <= c; i++) G[i][i] = 0;
        int u, v, w = 1;
        while (cin >> u >> v && u && v) 
        {
            G[u][v] = -1;
        }
        //print(c, G);
        
        for (int k = 1; k <= c; k++) 
        {  
            for (int i = 1; i <= c; i++) 
            {
                for (int j = 1; j <= c; j++) 
                {
                    G[i][j] = min(G[i][j], G[i][k]+G[k][j]);  
                }  
                
            } 
        }
        int max_len = 0, to = 0;
        for (int i = 1; i <= c; i++) 
        {
            if (G[s][i] < max_len) 
            {
                max_len = G[s][i];
                to = i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", Case++, s, -G[s][to], to);
    }
    return 0;
}
