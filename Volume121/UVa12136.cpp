/*
 * Problem: "UVa 12136 - Schedule of a Married Man"
 *  Author: "Jia_coding"
 * 
 *     Tag: 區間 - 時間
**/

#include <iostream>
using namespace std;
int main() {
    int t, Case = 1; 
  	cin >> t;
        while (t--) {
      	  int wh1, wm1, wh2, wm2;
      		scanf("%d:%d%d:%d", &wh1, &wm1, &wh2, &wm2);
          
          int mh1, mm1, mh2, mm2;//meeting
      		scanf("%d:%d%d:%d", &mh1, &mm1, &mh2, &mm2);
      		
      		int wL = wh1*60 + wm1; 
      		int wR = wh2*60 + wm2;
      		int mL = mh1*60 + mm1; 
      		int mR = mh2*60 + mm2;
      		
      		printf("Case %d: ", Case++);
      		if ((wL > mR) || (wR < mL)) printf("Hits Meeting\n");
      		else printf("Mrs Meeting\n");	
    }
}
