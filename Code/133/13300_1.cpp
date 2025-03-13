#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

// 用于比较两个点的极角，用于排序
bool compare(Point& a, Point& b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

// 计算叉积
int crossProduct(Point& p, Point& q, Point& r) {
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

// 寻找凸包上的点
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n <= 3) return points;

    sort(points.begin(), points.end(), compare);

    vector<Point> hull;

    // 下半部分
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    // 上半部分
    int lowerSize = hull.size();
    for (int i = n - 2; i >= 0; --i) {
        while (hull.size() > lowerSize && crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    hull.pop_back(); // 移除重复的起点

    return hull;
}

// 计算两点之间的距离的平方
double distanceSquared(Point& a, Point& b) {
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

// 计算三角形的面积
double triangleArea(Point& a, Point& b, Point& c) {
    double side1 = sqrt(distanceSquared(a, b));
    double side2 = sqrt(distanceSquared(b, c));
    double side3 = sqrt(distanceSquared(c, a));
    double s = (side1 + side2 + side3) / 2.0;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

int main() {
    int N;

    while (cin >> N) {

        vector<Point> lamps(N); // 存储燈柱位置的向量

        // 读取燈柱的位置
        for (int i = 0; i < N; ++i) {
            cin >> lamps[i].x >> lamps[i].y;
        }

        // 计算凸包
        vector<Point> convexHullPoints = convexHull(lamps);

        double maxTriangleArea = 0.0;

        // 遍历凸包上的所有三个点的组合，找出最大的三角形面积
        int hullSize = convexHullPoints.size();
        for (int i = 0; i < hullSize; ++i) {
            for (int j = i + 1; j < hullSize; ++j) {
                for (int k = j + 1; k < hullSize; ++k) {
                    double area = triangleArea(convexHullPoints[i], convexHullPoints[j], convexHullPoints[k]);
                    maxTriangleArea = max(maxTriangleArea, area);
                }
            }
        }

        printf("%.1f\n", maxTriangleArea);
    }

    return 0;
}
