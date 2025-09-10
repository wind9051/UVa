/*
 * Problem: "UVa 10175 - Sphere"
 *  Author: "Jia_coding"
 * 
 *     Tag: 幾何 - 球體(Sphere), 體積, 表面積
 *          幾何 - 兩球體相交 - 球冠 
 *          物理(Physics) - 浮力
**/

#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);

// 兩球交疊情況

// 球冠高度 H = r1 - (r1^2 - r2^2 + d^2) / 2d
double capHeight(double r1, double r2, double d) {
    return r1 - (r1*r1 - r2*r2 + d*d) / (2*d);
}

// 球冠體積 V = PI/3 * h^2 * (3R-h)
double sphericalCapVolume(double r, double h) {
    return PI * (h*h) * (3*r - h) / 3.0;
}

// 球體體積公式 V = 4/3 * PI * R^3
double sphereVolume(double r) {
    return (4.0/3.0) * PI * r*r*r;
}

// 球冠表面積公式 A = 2 * PI * r * h
double sphericalCapSurface(double r, double h) {
    return 2 * PI * r * h;
}

// 球體表面積公式 A = 4 * PI * r^2
double sphereSurface(double r) {
    return 4.0 * PI * r*r;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        double r1, r2, d, dw, ds;
        cin >> r1 >> r2 >> d >> dw >> ds;
        
        // 球冠高度
        double h1 = capHeight(r1, r2, d);
        double h2 = capHeight(r2, r1, d);
        
        //cout<<h1<<" "<<h2<<endl;
        
        // 球冠體積與表面積
        double V_overlap = sphericalCapVolume(r1, h1) + sphericalCapVolume(r2, h2);
        double A_overlap = sphericalCapSurface(r1, h1) + sphericalCapSurface(r2, h2);
    
        // 球體總體積與總表面積
        double V_total = sphereVolume(r1) + sphereVolume(r2);
        double A_total = sphereSurface(r1) + sphereSurface(r2);
        
        printf("%.4f %.4f\n", V_total - V_overlap, A_total - A_overlap);
        
    
        // 浮沉判斷
        if (dw / (V_total - V_overlap) < ds) printf("The Paired-Sphere Floats.\n");
        else printf("The Paired-Sphere Sinks.\n");
    }
    return 0;
}
