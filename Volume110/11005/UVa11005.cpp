/*
 * Problem:  "UVa 11005 - Cheapest Base"
 *  Author: "Jia_coding"
 * 
 *     Tag: 進制轉換
**/

#include <vector>
#include <iostream>
using namespace std;

int main () {
    int t, Case = 1;
    cin >> t;
    while (t--) {
        
        vector<int> cost(36, 0);
        for (int i = 0; i < 36; i++) cin >> cost[i];

        printf("Case %d:\n", Case++);
        int n;
        cin >> n;
        while (n--) {
            int x;
            cin >> x;
            vector<int> sum(36, 0);
            int minn = 10e8;
            for (int i = 2; i <= 36; i++) {
                int k = x, cnt = 0;
                while (k) {
                    cnt += cost[k % i];
                    k /= i;
                }
                sum[i] = cnt;
                minn = min(minn, cnt);
            }
            printf("Cheapest base(s) for number %d:", x);
            for (int i = 2; i <= 36; i++) {
                if (sum[i] == minn) cout << " " << i;
            }
            cout << endl;
        }
        if (t) cout << endl;
    }
    return 0;
}