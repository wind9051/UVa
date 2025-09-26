/*
 * Problem: "UVa 113 - Power of Cryptography"
 *  Notion: "https://titanium-cylinder-f1d.notion.site/00113-271d4158fd15808b876cfeb377032da7?source=copy_link"
 *  Author: "Jia_coding"
 * 
 *     Tag: 數學 - N次方根
**/


#include <cmath>
#include <iostream>
using namespace std;


int main() { 
    double n, p;
    while (cin >> n >> p) {
        //p^(1/n) = k
	      printf("%.0f\n", pow(p, 1.0 / n)); 
    }	
  	return 0;
}
