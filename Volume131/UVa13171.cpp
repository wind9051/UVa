/*
 * Problem: "UVa 13171 - Pixel Art"
 *  Author: "Jia_coding"
 * 
 *     Tag: 模擬
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
  	int t, m, y, c;
  	cin >> t;
  	while (t--) {
  	    
  	    int M, Y, C;
  	    string Color;
  		  cin >> M >> Y >> C >> Color;
  
    		for (auto& c : Color) {
    			if (c == 'M') M--;
    			if (c == 'Y') Y--;
    			if (c == 'C') C--;
    			if (c == 'R') M--, Y--;
    			if (c == 'V') M--, C--;
    			if (c == 'G') Y--, C--;
    			if (c == 'B') M--, Y--, C--;
    		}
    
    		if (M >= 0 && Y >= 0 && C >= 0) printf("YES %d %d %d\n", M, Y, C);
    		else printf("NO\n");
  	}
}