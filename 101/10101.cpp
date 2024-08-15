/*
 * Title:  "UVa10101 - Bangla Numbers"
 * Author: "Jia_coding"
 * Date:   "2024/08/15"
 */

#include <iostream>
using namespace std;
typedef long long ll;

int num[] = {10000000, 100000, 1000, 100};
string s[] = {"kuti", "lakh", "hajar", "shata"};

void solve(ll n) {
    //cout<<n<<endl;
	for (int i = 0; i < 4; i++) {
		if (n >= num[i]) {
			solve(n/num[i]);
			cout << " " << s[i]; 
			n %= num[i];
		}
	}
	if (n) cout << " " << n;
}


int main () {
	ll n;
	int Case = 1;
	while (cin >> n) {
		cout << Case++ << ".";
		if (n == 0) cout << " 0\n";
		else {
			solve(n);
			cout << "\n";
		}
	}
	return 0;
}
/*
Sample Input
23764
45897458973958
Sample Output
1. 23 hajar 7 shata 64
2. 45 lakh 89 hajar 7 shata 45 kuti 89 lakh 73 hajar 9 shata 58
*/
