/*
 * Problem: "UVa 13278 - Angry Birds Transformers"
 *  Author: "Jia_coding"
 * 
 *     Tag: 幾何(點) 掃描線
**/

#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

struct State {
    int x, value;
    
    bool operator <(const State & other) const {
        if (x != other.x) return x < other.x;
        else return value > other.value;
    }
};

int main() {
    int N;
    while (cin >> N && N) {
        vector<Point> pts(N);
        for (int i = 0; i < N; ++i) {
            cin >> pts[i].x >> pts[i].y;
        }
        
        vector<State> events;
        for (auto &p : pts) {
            events.push_back({p.x - p.y, +1}); 
            events.push_back({p.x + p.y, -1}); 
        }
        sort(events.begin(), events.end());

        int cur = 0, maxVisible = 0;
        for (auto &e : events) {
            cur += e.value;
            maxVisible = max(maxVisible, cur);
        }

        cout << maxVisible << "\n";
    }

    return 0;
}
