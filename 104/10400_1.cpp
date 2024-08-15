/*
 * Title:  "UVa10400 - Game Show Math"
 * Author: "Jia_coding"
 * Date:   "2024/08/15"
 */

#include <bits/stdc++.h>
using namespace std;
 
int n, e, num[110];
char op[110];
bool Vis[110][64010];
bool OK; 

void DFS(int d, int x)
{
    if (OK || x > 32000 || x < -32000) return;
 
    if (Vis[d][x+32000]) return;
 
    Vis[d][x+32000] = true;
    if (d == n - 1)
    {
        if(x == e)
        {
            OK = true;
            op[d] = '=';
        }
        return;
    }
 
    op[d] = '+';
    DFS(d + 1, x + num[d + 1]);
    if (OK) return;
 
    op[d] = '-';
    DFS(d + 1, x - num[d + 1]);
    if (OK) return;
 
    op[d] = '*';
    DFS(d + 1, x * num[d + 1]);
    if (OK) return;
 
    if (x % num[d + 1] == 0)
    {
        op[d] = '/';
        DFS(d + 1, x / num[d + 1]);
    }
}
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        
        for (int i = 0; i < n; i++) cin >> num[i];
        
        cin >> e;
        
        OK = 0;
        memset(Vis, 0, sizeof(Vis));
        
        DFS(0, num[0]);
        
        if (OK)
        {
            for (int i = 0; i < n; i++)
            {
                cout << num[i] << op[i];
            }
            cout << e << endl;
        }
        else
        {
            printf("NO EXPRESSION\n");
        }
    }
    return 0;
}
