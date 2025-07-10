#include <vector>
using namespace std;

struct Point {
    double x, y;
};

double cross(const Point& a, const Point& b, const Point& c) {
    // 計算向量ab x bc
    double x1 = b.x - a.x, y1 = b.y - a.y;
    double x2 = c.x - b.x, y2 = c.y - b.y;
    return x1 * y2 - y1 * x2;
}

bool isConvex(const vector<Point>& poly) {
    int n = poly.size();
    if (n < 3) return false;
    int sign = 0;
    for (int i = 0; i < n; ++i) {
        double c = cross(poly[i], poly[(i + 1) % n], poly[(i + 2) % n]);
        if (c != 0) {
            if (sign == 0)
                sign = (c > 0) ? 1 : -1;
            else if ((c > 0 && sign < 0) || (c < 0 && sign > 0))
                return false;
        }
    }
    return true;
}