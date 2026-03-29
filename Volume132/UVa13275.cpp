/*
 * Problem: "UVa 13275 - Leap Birthdays"
 *  Author: "Jia_coding"
 * 
 *     Tag: 日期閏年
**/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int Case = 1; Case <= t; Case++) {
        int d, m, y, qy, day;
        cin >> d >> m >> y >> qy;
        if (m == 2 && d == 29){
            day = 0;
            for (int i = y+1; i <= qy; i++) {
                if (i%4==0 && i%100!=0 || i%400==0) {
                    day++;
                }
            }
        }
        else {
            day = qy - y;
        }
        printf("Case %d: %d\n", Case, day);
    }
    return 0;
}
