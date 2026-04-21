/*
 * Problem: "UVa 12148 - Electricity "
 *  Author: "Jia_coding"
 * 
 *     Tag: 日期
**/

#include<bits/stdc++.h>
using namespace std;

struct Date {
    int d, m, y, c;
    void read() { cin >> d >> m >> y >> c; }
    void print() { cout << d << ' ' << m << ' ' << y << ' ' << c << endl; }
};


int f (int m, int y) {
    if (m==2) {
        if(y%400==0||(y%4==0&&y%100!=0))return 29;
        else return 28;
    }
    if(m==4||m==6||m==9||m==11)return 30;
    return 31;
}

bool check(Date a, Date b) {
    // x/y -> x/y+1
    if ((a.y==b.y) && (a.m==b.m) && (a.d+1==b.d)) return 1;
    // 12/31 -> 1/1
    if ((a.m==12&&a.d==31)&&(b.m==1&&b.d==1)&&(a.y+1==b.y))return 1;
    // x/y -> x+1/1
    if(a.d==f(a.m,a.y)&&(b.d==1&&a.m+1==b.m)&&(a.y==b.y))return 1;
    return 0;
}

int main() {
    int n;
    while (cin >> n && n) {
        Date pre, cur; 
        
        int cnt = 0, ans = 0;

        pre.read(); 
        for (int i = 1; i < n; i++) {
            cur.read();

            if (check(pre, cur)) {
                ans += cur.c - pre.c;
                cnt++;
            }
            pre = cur;
        }
        cout << cnt << ' ' << ans << '\n';
    }
    return 0;
}

