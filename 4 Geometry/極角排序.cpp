struct Point {
    int x, y;
};

// 以 base 為基準點，對 points 進行極角排序
void polarSort(vector<Point>& points, Point base) {
    sort(points.begin(), points.end(), [&](const Point& a, const Point& b) {
        int dx1 = a.x - base.x, dy1 = a.y - base.y;
        int dx2 = b.x - base.x, dy2 = b.y - base.y;
        long long cross = 1LL * dx1 * dy2 - 1LL * dy1 * dx2;
        if (cross != 0) return cross > 0;
        // 極角相同時，距離近的排前面
        return dx1 * dx1 + dy1 * dy1 < dx2 * dx2 + dy2 * dy2;
    });
}