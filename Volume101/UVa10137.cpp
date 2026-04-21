/*
 * Problem: "UVa 10137 - The Trip"
 *  Author: "Jia_coding"
 * 
 *     Tag: 浮點數
**/

#include <vector>
#include <iostream>
using namespace std;
int main () {
    int n;
    while (cin >> n && n) {
        int a, b, sum = 0;
        vector<int> num;
        for (int i = 0; i < n; i++) {
            scanf("%d.%d", &a, &b);
            num.push_back(a*100+b);
            sum += a * 100 + b;
        }
        int avg_L = sum / n;
        int avg_U = (sum % n == 0) ? avg_L : avg_L + 1;
        
        int take = 0, give = 0;
        for (auto x : num) {
            if (x > avg_U) give += x - avg_U;
            if (x < avg_L) take += avg_L - x;
        }

        int ans = max(take, give);
        printf("$%d.%02d\n", ans/100, ans%100);
    }
    return 0;
}