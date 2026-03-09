/*
 * Problem: "UVa 1009 - Balloons in a Box"
 *  Author: "Jia_coding"
 * 
 *     Tag: 排組（排列）　幾何（球）　枚舉
**/

#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

struct Point {
    double x,y,z;
};

struct Sphere {
    Point c;
    double r;
};

double dist(const Point& a, const Point& b){
    double dx = a.x - b.x, dy = a.y-b.y, dz = a.z-b.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main(){
    int n, Cas = 0;
    while (cin >> n && n) {
        Point box1, box2;
        cin >> box1.x >> box1.y >> box1.z;
        cin >> box2.x >> box2.y >> box2.z;

        double xmin = min(box1.x, box2.x), xmax = max(box1.x, box2.x);
        double ymin = min(box1.y, box2.y), ymax = max(box1.y, box2.y);
        double zmin = min(box1.z, box2.z), zmax = max(box1.z, box2.z);

        vector<Point> p(n);
        for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y >> p[i].z;

        vector<int> id(n);
        for (int i = 0; i < n; i++) id[i] = i;

        double best = 0;

        do {
            
            vector<Sphere> spheres;
            double cur = 0;
            for (int k = 0; k < n; k++) {
                Point A = p[id[k]];

                double r = min({A.x - xmin, xmax - A.x,
                                A.y - ymin, ymax - A.y,
                                A.z - zmin, zmax - A.z});

                if (r <= 0) continue;

                for (auto &s : spheres){
                    r = min(r, dist(A, s.c) - s.r);
                }

                if (r > 0) {
                    spheres.push_back({A, r});
                    cur += 4.0/3.0 * PI * r*r*r;
                }
            }
            best = max(best, cur);
            

        } while(next_permutation(id.begin(), id.end()));

        double boxVol = (xmax-xmin) * (ymax-ymin) * (zmax-zmin);
        long long ans = llround(boxVol - best);
        
        printf("Box %d: %d\n", ++Cas, ans);
        printf("\n");
    }
    return 0;
}
