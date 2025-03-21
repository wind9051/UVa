//UVA10924 Prime Words
#include <bits/stdc++.h>
using namespace std;

vector<int> N(1055, 1);
void init_sieve() {
    for (int i = 2; i*i <= 1050; i++) {
        if (N[i]) {
            for (int j = i+i; j <= 1050; j+=i) {
                N[j] = 0;
            }
        }
    }
}

int main () {
    init_sieve();
    
    string line;
    while (getline(cin, line)) {
        int sum = 0;
        for (auto c : line) {
            if (isupper(c)) sum += c - 'A' + 27;
            else sum += c - 'a' + 1;
        }
        if (N[sum]) printf("It is a prime word.\n");
        else printf("It is not a prime word.\n");
    }
    return 0;
}