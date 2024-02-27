#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 计算两点之间的距离的平方
double distanceSquared(int x1, int y1, int x2, int y2) {
    return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

// 计算三角形的面积
double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    double a = sqrt(distanceSquared(x1, y1, x2, y2));
    double b = sqrt(distanceSquared(x2, y2, x3, y3));
    double c = sqrt(distanceSquared(x3, y3, x1, y1));
    double s = (a + b + c) / 2; // 半周长
    return sqrt(s * (s - a) * (s - b) * (s - c)); // 海伦公式计算面积
}

int main() {
    int N;
    while (cin >> N)  {
        vector<pair<int, int>> lamps(N); // 存储燈柱位置的向量

        // 读取燈柱的位置
        for (int i = 0; i < N; ++i) {
            int x, y;
            cin >> x >> y;
            lamps[i] = {x, y};
        }

        double maxArea = 0; // 最大面积初始化为0

        // 遍历每三个燈柱的组合，计算三角形面积，找到最大值
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = j + 1; k < N; ++k) {
                    double area = triangleArea(lamps[i].first, lamps[i].second,
                                               lamps[j].first, lamps[j].second,
                                               lamps[k].first, lamps[k].second);
                    maxArea = max(maxArea, area);
                }
            }
        }
        printf("%.1f\n", maxArea);
    }
    return 0;
}

/*读取输入：首先读取输入的测试用例数量，然后对于每个测试用例，读取燈柱的数量以及它们的位置坐标。
对于每个测试用例，计算最大面积：对于每三个燈柱，计算由它们形成的三角形的面积，找到最大的三角形面积作为最大可见区域的候选值。
输出结果：将最大面积输出到标准输出。
O(T*N^3)
*/