/*
 * Problem: "UVa 12207 - That is Your Queue"
 *  Author: "Jia_coding"
 * 
 *     Tag: List
**/

#include <list>
#include <iostream>
using namespace std;

char ch;

int main () {
	int p, c, Case = 1;
	while (cin >> p >> c && p+c != 0) {
	  
		list <int> que;
		
		for (int i = 1; i <= min(p, c); i++) que.push_back(i);
		
		printf("Case %d:\n", Case++);
		for (int i = 0; i < c; i++) {
			cin >> ch;
			if (ch == 'N') {
				cout << que.front() <<endl;
				que.push_back(que.front());
				que.pop_front();
			}
			else {
			    int x;
			    cin >> x;
			    que.remove(x);
			    que.push_front(x);
			}
		}
	}
	return 0;
}