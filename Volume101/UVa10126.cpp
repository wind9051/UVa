/*
 * Problem: "UVa 10126 - Zipfs Law"
 *  Author: "Jia_coding"
 * 
 *     Tag: 字串, 哈希(Hash)
**/

#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main () {
	int find, Case = 0;
	while (cin >> find) {
		cin.ignore();
		
		string str; 
		map <string , int> words;  
		while (cin >> str) {
		  
		    if (str == "EndOfText") break;
  			str += "#";
  			string key = "";
  			for (int i = 0; i < str.size(); i++) {
    				if (isalpha(str[i])) {
      					key += tolower(str[i]);
    				}
    				else {
      				  words[key]++;
      				  key = "";
    				}
  			}
		}	
		
    bool flag = 0;
		if (Case++) printf("\n");
		for (auto [u, v] : words) {
		    //cout<< u <<" "<<v<<endl;
  			if (find == v) {
  			    cout << u << endl;
  				  flag = true;	
  			}
		}
		if (!flag) printf("There is no such word.\n");
	}
	return 0;
}