/*
 * Title:  "UVa11000 - Bee"
 * Author: "Jia_coding"
 * Date:   "2024/08/15"
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() 
{
    vector<ll> mbee(70, 0), fbee(70, 1);
    
    mbee[1] = 1;
    for (int i = 2; i < 70; i++) 
    {
        mbee[i] = mbee[i-1] + fbee[i-1];
        fbee[i] = fbee[i-1] + fbee[i-2];
    }
    
    int n;
    while (cin >> n && n != -1) 
    {
        printf("%lld %lld\n", mbee[n], mbee[n]+fbee[n]);
    }
    return 0;
}
