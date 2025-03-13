/*
 * Problem: "UVa 10502 - Counting Rectangles"
 *  Author: "Jia_coding"
 *    Date: "2025/03/13"
 *     Tag: PreSum, Matrix, Grid, DP
 *          前綴和, 矩陣, 網格, 動態規劃
 * 
**/

#include <iostream>
#include <vector>
using namespace std;

int countRectangles(vector<vector<int>> &G, int h, int w) {
    vector<vector<int>> preH(h, vector<int>(w, 0));
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (G[i][j]) {
                if (i == 0) preH[i][j] = 1;
                else preH[i][j] = preH[i - 1][j] + 1;
            }
        }
    }
    /*
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout<<preH[i][j]<<" ";
        }
        cout<<endl;
    }cout<<endl;
    */

    int count = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int minHeight = preH[i][j];
            for (int k = 0; j - k >= 0; ++k) { 
                minHeight = min(minHeight, preH[i][j - k]);
                //cout<<i<<" "<<j<<" "<<minHeight<<endl;
                count += minHeight;
            }
        }
    }

    return count;
}

int main() {
    int h, w;
    while (cin >> h >> w && h) {
        vector<vector<int>> G(h, vector<int>(w));
        
        for (int i = 0; i < h; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < w; ++j) {
                G[i][j] = row[j] - '0';
            }
        }
        cout << countRectangles(G, h, w) << endl;
    }
    return 0;
}
