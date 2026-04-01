/*
 * Problem: "UVa 10141 - Request for Proposal"
 *  Author: "Jia_coding"
 * 
 *     Tag: 模擬(Simulation)
**/

#include <bits/stdc++.h>
using namespace std;


int main () {
    int n, p, Case = 0;
    while (cin >> n >> p) {
        if (n == 0 && p == 0) break;
        
        string req;
        
        cin.ignore();
        for (int i = 0; i < n; i++) getline(cin, req); //ignore
        

        string bestName;
        double bestPrice = 1e9;
        int bestR = -1;
        for (int i = 0; i < p; i++) {
            string Name;
            getline(cin, Name);

            double price;
            int R;
            cin >> price >> R;
            
            cin.ignore();
            for (int j = 0; j < R; j++) getline(cin, req); //ignore

            if (R > bestR || (R == bestR && price < bestPrice)) {
                bestR = R;
                bestPrice = price;
                bestName = Name;
            }
            //cout <<bestName<<" "<<bestR<<" "<<bestPrice<<endl;
        }
        if (Case) printf("\n");
        printf("RFP #%d\n%s\n", ++Case, bestName.c_str());
    }
}