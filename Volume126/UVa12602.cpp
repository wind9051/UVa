/*
 * Problem: "UVa 12602 - Nice Licence Plates
 *  Author: "Jia_coding"
 * 
 *     Tag: 字串
**/

#include <cmath>
#include <iostream>
using namespace std;
int main(){
    int t; 
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;

        int pos = s.find('-');
        string alpha = s.substr(0, pos);
        int num = stoi(s.substr(pos + 1));

        int sum = 0;
        for (int i = 0; i < 3; i++){
            sum += (alpha[i]-'A') * pow(26, (2-i));
        }
        if (abs(num-sum) <= 100) printf("nice\n");
        else printf("not nice\n");
    }	
    return 0;
}

