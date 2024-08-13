//UVA10900 So you want to be a 2n - aire?
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double t;
    while (cin >> n >> t && n)
    {
        vector<double> DP(n+5, 0.0);
        DP[n] = 1 << n; // 2^i
        
        //DP[i] = max(2^n, p*DP[i+1])
        for (int i = n-1; i >= 0; i--)
        {
            double p0 = max(t, double(1<<i) / DP[i+1]);
            double p1 = (p0-t) / (1-t);
            DP[i] = p1 * (1<<i) + (1-p1) * (1+p0)/2*DP[i+1];
        }
        printf("%.3f\n", DP[0]);
    }
    return 0;
}
