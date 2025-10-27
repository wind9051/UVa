/*
 * Problem: "UVa 13216 - Problem with a ridiculously long name but with a ridiculously short description"
 *  Author: "Jia_coding"
 * 
 *     Tag: math(數學), mod(餘數)
 * 
**/

#include <bits/stdc++.h>
using namespace std;

int mod[] = {76, 16, 56, 96, 36};
    
int main () {
    int t;
    cin >> t;
    
    while (t--) {
        string n;
        cin >> n;
        if (n == "0") printf("1\n");
        else if (n == "1") printf("66\n");
        else {
           printf("%d\n", mod[(n[n.size()-1]-'0') % 5]);
        }
    }
    return 0;
}