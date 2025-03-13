//uva13300

#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

struct pt {
    ld x, y;
};

int orientation(pt a, pt b, pt c) {
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0) return -1;  
    if (v > 0) return +1; 
    return 0;
}

ld cross(ld x1, ld y1, ld x2, ld y2) { 
    return x1 * y2 - x2 * y1; 
}

bool cw(pt a, pt b, pt c) {
    return orientation(a, b, c) < 0;
}

void convex_hull(vector<pt>& v) {
    pt p0 = *min_element(v.begin(), v.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });

    sort(v.begin(), v.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x - a.x) * (p0.x - a.x) + (p0.y - a.y) * (p0.y - a.y) <
                   (p0.x - b.x) * (p0.x - b.x) + (p0.y - b.y) * (p0.y - b.y);
        return o < 0;    
    });

    vector<pt> st;
    for (auto& p : v) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), p))
            st.pop_back();
        st.push_back(p);
    }
    v = st;
}

int main () {
    int n;
    while (cin >> n) {
        ld ans = 0.0;

        vector<pt> V(n);
        for (auto& p : V) cin >> p.x >> p.y;

        convex_hull(V);
        

        for (int i = 0; i < V.size(); i++) {
            int j = i + 1, k = j + 1;

            while (k < V.size()) {
                pt ij = {V[i].x - V[j].x, V[i].y - V[j].y};
                pt ik = {V[i].x - V[k].x, V[i].y - V[k].y};
                pt ijp = {V[i].x - V[j + 1].x, V[i].y - V[j + 1].y};
                pt ikp = {V[i].x - V[(k + 1) % n].x, V[i].y - V[(k + 1) % n].y};

                ld cross_ijk = abs(cross(ij.x, ij.y, ik.x, ik.y));
                ld cross_ijkp = abs(cross(ij.x, ij.y, ikp.x, ikp.y));
                ld cross_ijpk = abs(cross(ijp.x, ijp.y, ik.x, ik.y));

                ans = max(ans, cross_ijk);

                if (j == k || cross_ijpk < cross_ijkp)
                    k++;
                else
                    j++;
            }
        }
        printf("%.1Lf\n", ans / 2.0);
    }
    return 0;
}