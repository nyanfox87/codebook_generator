#include <vector>
using namespace std;

struct Point {
    double x, y;
};

bool onSegment(Point a, Point b, Point p) {
    // 判斷點p是否在線段ab上
    return (min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)) &&
           (min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y)) &&
           ((b.x - a.x) * (p.y - a.y) == (b.y - a.y) * (p.x - a.x));
}

bool pointInPolygon(const vector<Point>& poly, Point p) {
    int n = poly.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        Point a = poly[i], b = poly[(i + 1) % n];
        // 檢查是否在邊上
        if (onSegment(a, b, p)) return true;
        // 保證a.y <= b.y
        if (a.y > b.y) swap(a, b);
        // 射線與邊相交
        if (a.y <= p.y && p.y < b.y) {
            double x = a.x + (b.x - a.x) * (p.y - a.y) / (b.y - a.y);
            if (x > p.x) cnt++;
        }
    }
    return cnt % 2 == 1;
}