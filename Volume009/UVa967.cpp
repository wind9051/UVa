/*
 * Problem : UVa 967 - Circular
 *  Author : Jia_coding
 *
 *     Tag : 質數 / Circular Prime / Sieve
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;

vector<bool> is_prime(MAXN+1, true);
void sieve_eratosthenes() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= MAXN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

bool isCircular(int n) {
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++) {

        int val = stoi(s);

        if (!is_prime[val]) return false;

        rotate(s.begin(), s.begin() + 1, s.end());
    }
    return true;
}


vector<int> initPrefix() {
    vector<int> pre(MAXN + 1, 0);
    for (int i = 100; i <= MAXN; i++) {
        pre[i] = pre[i - 1];
        if (isCircular(i)) pre[i]++;
    }
    return pre;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    sieve_eratosthenes();

    vector<int> pre = initPrefix();

    int a, b;
    while (cin >> a >> b && a != -1) {

        int cnt = pre[b] - pre[a - 1];

        if (cnt == 0)
            cout << "No Circular Primes.\n";
        else if (cnt == 1)
            cout << "1 Circular Prime.\n";
        else
            cout << cnt << " Circular Primes.\n";
    }

    return 0;
}