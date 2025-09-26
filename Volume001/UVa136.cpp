/*
 * Problem: "UVa 136 - Ugly Numbers"
 *  Notion: "https://titanium-cylinder-f1d.notion.site/00136-271d4158fd15808d9627dc0f44965308?source=copy_link"
 *  Author: "Jia_coding"
 * 
 *     Tag: 因數 - 醜數, 雙指針
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> Num(1505, 0);
    Num[1] = 1;
    
  	int p2 = 1, p3 = 1, p5 = 1;
  	for (int i = 2; i <= 1500; i++) {
  		  while (Num[p2] * 2 <= Num[i-1]) p2++;
  		  while (Num[p3] * 3 <= Num[i-1]) p3++;
  		  while (Num[p5] * 5 <= Num[i-1]) p5++;
  		  Num[i] = min(Num[p2] * 2, min(Num[p3] * 3, Num[p5] * 5));
  	}
  	printf("The 1500'th ugly number is %d.\n", Num[1500]);
	  
	  return 0;
}
//1 2 3 4 5 6 8 9 10 12
