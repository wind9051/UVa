/*
 * Problem: "UVa 213 - Message Decoding"
 *  Author: "Jia_coding"
 * 
 *     Tag: String
**/

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> code(8);

char readChar() {
    char c;
    while (cin.get(c)) {
        if (c != '\n' && c != '\r') return c;
    }
    return EOF;
}

int readLen(int l) {
    int val = 0;
    for (int i = 0; i < l; ++i) {
        val = val * 2 + (readChar() - '0');
    }
    return val;
}

int main() {
    string header;
    while (getline(cin, header) && header.size()) {
        // cout << header<<endl;
        for (int i = 0; i < 8; ++i) {
            code[i].assign((1 << i)-1, 0);
        }

        int L = 0;
        code[1][0] = header[L++];
        for (int len = 2; len <= 7; len++) {
            for (int u = 0; u < (1 << len) - 1; u++) {
                if (L > header.size()) break;
                code[len][u] = header[L++];
            }
        }
        
        while (true) {
            int len = readLen(3);
            if (len == 0) break;

    
            while (true) {
                int idx = readLen(len);
                if (idx == (1 << len) - 1) break;
                cout << code[len][idx];
            }
        }
        cout << '\n';

        cin.get();
    }
    return 0;
}
