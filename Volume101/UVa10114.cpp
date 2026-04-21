/*
 * Problem: "UVa 10114 - Loansome Car Buyer"
 *  Author: "Jia_coding"
 * 
 *     Tag: 模擬
**/

#include <bits/stdc++.h> 
using namespace std;

struct Depreciation{
    int month;        
    double percentage; 
};

int main () {
    int m, d;
    double now, loan; 
    while (cin >> m >> now >> loan >> d && m >= 0) { 
			double car = now + loan;
			
			double pay = loan / m; 
			
			vector<Depreciation> rate(d); 
			for (int i = 0; i < d; i++) { 
			    cin >> rate[i].month >> rate[i].percentage;
			}
			
			int nowMonth, L = 0; 
      for (nowMonth = 0; nowMonth < m; ++nowMonth) { 
          if (L < d-1 && rate[L+1].month <= nowMonth) L++; 
  
          car *= (1 - rate[L].percentage); 
        
          if (car >= loan){ 
              break;
          }
  
          loan -= pay; 
      }
      if (nowMonth == 1) printf("%d month\n", nowMonth); 
      else printf("%d months\n", nowMonth);
    }
    return 0;
}