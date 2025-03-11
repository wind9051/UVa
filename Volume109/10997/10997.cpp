//Steven Kester Yuwono - UVa 10997

#include <bits/stdc++.h>
using namespace std;

bool canadaWins(vector<vector<int>> & medals, int n, int canadaIndex) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1;j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				int maxIndex = -1;
				int maxScore = -1;
				for (int z = 0; z < n; z++) {
					int score = i*medals[z][0] + j*medals[z][1] + k*medals[z][2];
					
					if (maxScore < score){
						maxScore = score;
						maxIndex = z;
					}
				}
				if (maxIndex == canadaIndex) return true;
			}
		}
	}
	return false;
}

int main() {
	int n;
	while (cin >> n && n) {
		int canadaIndex = -1;
		vector<vector<int>> medals(21, vector<int>(3));
		for (int i = 0; i < n; i++) {
			string country;
			cin >> country >> medals[i][0] >> medals[i][1] >> medals[i][2];

			if (country == "Canada") canadaIndex = i;
		}
		
		if (canadaWins(medals, n, canadaIndex)) printf("Canada wins!\n");
		else printf("Canada cannot win.\n");
	}
	return 0;
}
