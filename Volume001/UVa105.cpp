/*
 * Problem: "UVa 105 - The Skyline Problem "
 *  GitHub: "https://github.com/wind9051/UVa"
 *  Notion: "https://titanium-cylinder-f1d.notion.site/00105-269d4158fd15804d8ea1c30784bd2e13?source=copy_link"
 *  Author: "Jia_coding"
 * 
 *     Tag: 陣列, 區間, 掃描線
**/

#include<bits/stdc++.h>
using namespace std;

int L, H, R;

int main() {
    vector<int> Sky(10005, 0);
    int maxR = 0, minL = 10000;
  	while (cin >> L >> H >> R) {
    		for (int i = L; i < R; i++){
    			  Sky[i] = max(Sky[i], H);
    		}
    		maxR = max(maxR, R);
    		minL = min(minL, L);
    		//for (auto x : Sky) cout<<x<<" ";cout<<endl;
  	}
  	for (int i = minL; i <= maxR; i++){
  		  if (Sky[i-1] != Sky[i]){
  			    cout << i << " " << Sky[i];
  			    if (i != maxR) cout << " ";
  		  }	
  	}
  	cout << endl;
  	return 0;
}
