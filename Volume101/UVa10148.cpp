/*
 * Problem: "UVa 10148 - Advertisement"
 *  Author: "Jia_coding"
 *
 *     Tag: 貪心(Greedy), 區間(Interval)
**/

#include <bits/stdc++.h>
using namespace std;

int shift = 10000;

struct Line {
    int l, r;
};

bool cmp(Line A, Line B) {
    if (A.r != B.r) return A.r < B.r;
    return A.l < B.l;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int K, N;
        cin >> K >> N;

        vector<Line> L;
        vector<int> vis(20005, 0);

        int bound_l = 20005, bound_r = 0;

        for (int i = 0; i < N; i++) {
            int l, r;
            cin >> l >> r;
            l += shift;
            r += shift;
            if (l > r) swap(l, r);

            L.push_back({l, r});
            bound_l = min(bound_l, l);
            bound_r = max(bound_r, r);
        }
        sort(L.begin(), L.end(), cmp);

        for (auto &seg : L) {
            int l = seg.l, r = seg.r;

            int cnt = 0;
            for (int i = r; i >= l; i--) {
                if (vis[i]) cnt++;
            }

            for (int i = r; i >= l && cnt < K; i--) {
                if (!vis[i]) {
                    vis[i] = 1;
                    cnt++;
                }
            }
        }

        vector<int> ans;
        for (int i = bound_l; i <= bound_r; i++) {
            if (vis[i]) ans.push_back(i - shift);
        }

        cout << ans.size() << "\n";
        for (int x : ans) cout << x << "\n";

        if (t) cout << "\n";
    }
    return 0;
}