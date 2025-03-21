/*
 * Problem: "UVa 10958 - How Many Solutions?"
 *  Author: "Jia_coding"
 * 
 *     Tag: math(數學), 分數, prime(質數) divisor(因數), Sieve of Eratosthenes(埃拉托斯特尼篩法)
 * 
 *    Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1899
**/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e6;

vector<int> primes;
vector<bool> Num(MAX+5, true);
// Sieve of Eratosthenes
void init_sieve() {
    for (int i = 2; i*i <= MAX; ++i) {
        if (Num[i]) {
            primes.push_back(i);
            for (int j = i+i; j <= MAX; j += i) {
                Num[j] = false;
            }
        }
    }
}

//
int numDiv(long long N) {
    N = abs(N);
    
    int ans = 1, idx = 0;
    int p = primes[0];
    while (1LL * p * p <= N) {
        int e = 0;
        while (N % p == 0) {
            ++e;
            N /= p;
        }
        // e is the power of prime p in N
        // ans is the number of divisors of N
        // (e + 1) is the number of divisors of p^e
        // multiply them to get the total number of divisors of N^2 * p^e *... * p^e
        ans *= (e + 1);
        p = primes[++idx];
    }
    // If N is not 1, N^2 will have 2 more divisors
    if (N != 1) ans <<= 1;
    return ans;
}

int main() {
    init_sieve();
    
    int m, n, p, tc = 1;
    while (cin >> m >> n >> p) {
        if (m == 0 && n == 0 && p == 0) break;
        cout << "Case " << tc++ << ": " << (numDiv(1LL * p * p * n * m) * 2 - 1) << "\n";
    }
    return 0;
}
