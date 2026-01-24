/*
 * Problem: "UVa 190 - Circle Through Three Points"
 *  Author: "Jia_coding"
 * 
 *     Tag: 矩陣　幾何（圓）
**/

#include <bits/stdc++.h>
using namespace std;

void getCircleCenter(double x1,double y1, double x2,double y2, double x3,double y3, double &D ,double &E, double &Ox ,double &Oy) {
    double a1 = x2 - x1, b1 = y2 - y1, c1 = x1 * x1 + y1 * y1 - x2 * x2 - y2 * y2;
    double a2 = x3 - x1, b2 = y3 - y1, c2 = x1 * x1 + y1 * y1 - x3 * x3 - y3 * y3;
    //a1D + b1E = c1
    //a2D + b2E = c2
    
    //分母0
    if (fabs(a1) >= 1e-9) {
        double k = a2 / a1;
        E = (c2 - k*c1) / (b2 - k*b1);
        D = (c1 - b1 * E) / a1;
    }
    else {
        double k = a1 / a2;
        E = (c1 - k*c2) / (b1 - k*b2);
        D = (c2 - b2 * E) / a2;
    }
    
    Ox = -D / 2;
    Oy = -E / 2;
    
    return;
}

double dist_Euclidean(double x1, double x2, double y1, double y2) {
    return sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
}


int main() {
    double x1, y1, x2, y2, x3, y3;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        double D, E, Ox, Oy;
        getCircleCenter(x1, y1, x2, y2, x3, y3, D, E, Ox, Oy);
    
        double r = dist_Euclidean(Ox, x1, Oy, y1);

        double F = Ox*Ox + Oy*Oy - r*r;

        //(x-Ox)^2 + (y-Oy)^2 = r^2
        printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n", (Ox >= 0) ? '-' : '+', fabs(Ox), (Oy >= 0) ? '-' : '+', fabs(Oy), r);
        
        //x^2 + y^2 + Dx + Ey + F = 0
        printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n", (D >= 0) ? '+' : '-', fabs(D), (E >= 0) ? '+' : '-', fabs(E), (F >= 0) ? '+' : '-', fabs(F));
        

        printf("\n");
      
    }
  	return 0;
}
