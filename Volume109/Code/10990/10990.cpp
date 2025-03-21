#include<bits/stdc++.h>
using namespace std;
#define M 2000000

vector<long long> eulerPhi(M+1), step(M+1);
void init_oula() {
    eulerPhi[1] = 1;
    for (int i = 2; i <= M; i++)  eulerPhi[i] = i;
    for (int i = 2; i <= M; i++) {
       	if (eulerPhi[i] == i) {
            for (int j = i; j <= M; j += i) {
                eulerPhi[j] = (eulerPhi[j] / i) * (i - 1);
            }
        }
    }
}

void init_step() {
	for (int i = 2; i <= M; i++) {
        if (eulerPhi[i] == 1) step[i] = 1;
    } 
    for (int i = 2; i <= M; i++) {
		if (!step[i]) step[i] = step[eulerPhi[i]] + 1;
    }
}
int main(){
    init_oula();
    init_step();

    int t;
    cin >> t;
    while (t--) {
        int sum = 0;
        int a, b;
        cin >> a >> b;
	    for (int i = a; i <= b; i++) sum += step[i];
	    cout << sum << endl;
	}
    return 0;
}
