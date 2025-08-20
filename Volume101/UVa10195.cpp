/*
 * Problem: "UVa 10195 - The Knights Of The Round Table"
 *  Author: "Jia_coding"
 *
 *     Tag: 三角形, 內接圓
 *
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c;
    while(cin >> a >> b >> c) {
        double s = (a+b+c) / 2;
        double A = sqrt(s*(s-a)*(s-b)*(s-c));

        if (a == 0 || b == 0 || c == 0) A = 0, s = 1;

        printf("The radius of the round table is: %.3lf\n", A / s);
    }
    return 0;
}
