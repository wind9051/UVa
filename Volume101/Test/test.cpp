#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (cin >> n) {
        double x, y;
        double minx, miny, maxx, maxy;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            minx = min(minx, x);
            miny = min(miny, y);
            maxx = max(maxx, x);
            maxy = max(maxy, y);
        }
        printf("%.4f\n", (maxy-miny) * (maxx - minx));
    }
    return 0;
}

2 4 6 8 10