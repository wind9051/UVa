/*
 * Title:  "UVa 10910 - Marks Distribution"
 * Author: "Jia_coding"
 *   
 *    tag: math(數學), combinatorics(組合數學)
**/

#include <iostream>
#include <vector>
using namespace std;

//C(n, k)
int Comb(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    
    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, T, P;
        cin >> N >> T >> P;
        int rem = T % P;
        cout << Comb(N+rem-1, N-1) << endl;
    }

    return 0;
}
