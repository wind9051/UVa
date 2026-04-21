/*
 * Problem: "UVa 10140 - Prime Distance"
 *  Author: "Jia_coding"
 *
 *     Tag: 數論(Number Theory), 
 *          質數(Prime), 埃式篩(Sieve of Eratosthenes), 區間篩(Segmented Sieve)
 *
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int L, R;

vector<ll> Prime;
vector<bool> Num(50005, 1);
void sieve_eratosthenes(int N) {
    for (int i = 2; i <= N; i++) {
        if (Num[i]) {
            Prime.push_back(i);
            for (int j = i+i; j <= N; j+=i) {
                Num[j] = 0;
            }
        }
    }
}

vector<bool> isPrime;
void sieve_Segmented() {
    ll SqrtR = sqrt(R);
    //篩出 √R 的小質數
    sieve_eratosthenes(SqrtR);

    //建L~R偏移0~R-L+1陣列
    isPrime.assign(R-L+1, 1);
    for (ll & p : Prime) {
        ll start = max(p*p, ((L+(p-1)) / p) * p);
        for (ll j = start; j <= R; j += p) {
            isPrime[j-L] = 0;
        }
    }

    if (L == 1) isPrime[0] = 0;
}

int main () {
    while (cin >> L >> R) {
        if (L > R) swap(L, R);

        sieve_Segmented();

        vector<int> inrange;
        for (int i = 0; i < R-L+1; i++) {
            if (isPrime[i]) inrange.push_back(i+L);
        }

        if (inrange.size() < 2) printf("There are no adjacent primes.\n");
        else {
            ll minn = 1e9, maxn = -1;
            pair<ll, ll> A, B;
            for (int i = 1; i < inrange.size(); i++) {
                int now = inrange[i] - inrange[i-1];
                if (now < minn) {
                    A = {inrange[i-1], inrange[i]};
                    minn = now;
                }
                if (now > maxn) {
                    B = {inrange[i-1], inrange[i]};
                    maxn = now;
                }
            }
            printf("%lld,%lld are closest, %d,%d are most distant.\n", A.first, A.second, B.first, B.second);
        }
    }
    return 0;
}