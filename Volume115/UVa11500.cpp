/*
 * Problem: "UVa 11500 - Vampires"
 *  Author: "Jia_coding"
 * 
 *     Tag: 機率(賭徒破產問題)
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    double EV1, EV2, AT, D;
    while (cin >> EV1 >> EV2 >> AT >> D) {
        if (EV1 + EV2 + AT + D == 0.0) break;
        
        EV1 = ceil(EV1 / D);
        EV2 = ceil(EV2 / D);
        
        double p = AT / 6.0;
        double q = 1 - p;
        
        double res;
        if (AT == 3) {
            res = EV1 / (EV1 + EV2);
        } 
        else {
            res = (1 - pow(q / p, EV1)) / (1 - pow(q / p, EV1 + EV2));
        }
        
        printf("%.1lf\n", res * 100);
    }
    return 0;
}