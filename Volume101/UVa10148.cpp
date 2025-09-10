/*
 * Problem: "UVa 10148 - Advertisement"
 *  Author: "Jia_coding"
 *
 *     Tag: 貪心(Greedy), 區間(Interval)
 *          
 *
**/

#include <bits/stdc++.h>
using namespace std;

int shift = 10000;

struct Line {
    int l, r;
};

bool cmp(Line & A, Line & B) {
    if (A.r != B.r) return A.r < B.r;
    return A.l < B.l;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int K, N;
        cin >> K >> N;

        int bound_l = 20005;
        int bound_r = 0;
        vector<Line> L;
        vector<int> Vis(20005, 0);
        while (N--) {
            int l, r;
            cin >> l >> r;
            l += shift;
            r += shift;

            if (l > r) swap(l, r);

            bound_l = min(bound_l, l);
            bound_r = max(bound_r, r);

            L.push_back({l, r});
        }
        sort(L.begin(), L.end(), cmp);

        int ans = 0;
        for (auto A : L) {
            int cnt = 0;
            for (int i = A.r; i >= A.l && cnt < K; i--) {
                if (Vis[i]) cnt++;
            }

            for (int i = A.r; i >= A.l && cnt < K; i--) {
                if (!Vis[i]) {
                    cnt++;
                    ans++;
                    Vis[i] = 1;
                }
            }
        }
        printf("%d\n", ans);
        for (int i = bound_l; i <= bound_r; i++) {
            if (Vis[i]) printf("%d\n", i-shift);
        }

        if (t) printf("\n");
    }
    return 0;
}