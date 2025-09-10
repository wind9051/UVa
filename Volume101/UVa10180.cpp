/*
 * Problem: "UVa 10180 - Rope Crisis in Ropeland!"
 *  Author: "Jia_coding"
 *
 *     Tag: 數學(Math), 歐幾里得距離(Euclidean Distance)
 *          幾何, 直線方程(兩點式, 斜截式)
 *          點到直線距離(Point-Line Distance)
 *          圓與線的關係(Circle-Line Intersection)
 *          三角函數(Trigonometry, acos)
 *
**/

#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double dist_Euclidean(double x1, double x2, double y1, double y2) {
    return sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
}

bool check(Point A, Point B, double x, double y) {
    double minx = min(A.x, B.x);
    double miny = min(A.y, B.y);
    double maxx = max(A.x, B.x);
    double maxy = max(A.y, B.y);
    return (minx <= x && x <= maxx && miny <= y && y <= maxy);
}

bool Judge(Point & PA, Point & PB, double & R) {
    //y軸平行
    if (PA.x == PB.x) {
        if (abs(PA.x) >= R) return true;
        else {
            if (PA.y * PB.y > 0) return true;
            else return false;
        }
    }
    //x軸平行
    if (PA.y == PB.y) {
        if (abs(PA.y) >= R) return true;
        else {
            if (PA.x * PB.x > 0) return true;
            else return false;
        }
    }
    //直線一般式Ax + By + C = 0
    double A = PA.y - PB.y; //y1-y2
    double B = PB.x - PA.x; //x2-x1
    double C = (PB.y - PA.y) * PA.x - (PB.x - PA.x) * PA.y;
    //printf("%.3fx + %.3fy + %.3f = 0\n", A, B, C);
    
    //點到直線距離 d = |Ax+By+C| / sqrt(A^2 + B^2)
    double d = abs(C) / sqrt(A*A + B*B);

    if (d >= R) return true;
    else {
        //cout<<"t3\n";
        //斜截式 y = kx + b
        double k = -(A / B);
        double b = -(C / B);
        //printf("y = %.3fx + %.3f\n", k, b);

        //圓點垂足方程式 y = (kt) x
        double kt = -1.0 / k;
        //printf("y = %.3fx\n", kt);
        
        //(k)x + b = (kt)x
        //b = x(kt-k)
        //x = b/(kt-k)
        double x = b / (kt - k);
        double y = kt * x;

        if (check(PA, PB, x, y)) return false;
        else return true;
    }

    return true;
}

int main () {
	int t;
    cin >> t;
    while (t--) {
        double R;
        Point A, B, O;
        O.x = 0.0; O.y = 0.0;
        cin >> A.x >> A.y >> B.x >> B.y >> R;
        
        if (Judge(A, B, R)) {
            //AB直線距離
            printf("%.3f\n", dist_Euclidean(A.x, B.x, A.y, B.y));
        }
        else {
            double OA = dist_Euclidean(A.x, 0, A.y, 0);
            double OB = dist_Euclidean(B.x, 0, B.y, 0);
            double AB = dist_Euclidean(A.x, B.x, A.y, B.y);
                 
            double AC = sqrt(OA*OA - R*R);
            double BD = sqrt(OB*OB - R*R);

            //cosC = a^2+b^2-c^2 / 2ab
            double cosAOC = acos((R*R + OA*OA - AC*AC) / (2.0*R*OA));
            double cosBOD = acos((R*R + OB*OB - BD*BD) /(2.0*R*OB));
            double cosAOB = acos((OA*OA + OB*OB - AB*AB) / (2.0*OA*OB));
            double cosCOD = cosAOB - cosAOC - cosBOD;

            printf("%.3f\n", AC + BD+ cosCOD*R);
        }
    }
	return 0;
}
