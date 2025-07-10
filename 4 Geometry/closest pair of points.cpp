struct Point {
    double x, y;
    bool operator<(const Point& p) const { return x < p.x || (x == p.x && y < p.y); }
};

double dist(const Point& a, const Point& b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double closestPair(vector<Point>& pts, int l, int r) {
    if (r - l <= 3) {
        double d = 1e20;
        for (int i = l; i < r; ++i)
            for (int j = i + 1; j < r; ++j)
                d = min(d, dist(pts[i], pts[j]));
        sort(pts.begin() + l, pts.begin() + r, [](const Point& a, const Point& b) { return a.y < b.y; });
        return d;
    }
    int m = (l + r) / 2;
    double xmid = pts[m].x;
    double d = min(closestPair(pts, l, m), closestPair(pts, m, r));
    vector<Point> tmp;
    merge(pts.begin() + l, pts.begin() + m, pts.begin() + m, pts.begin() + r, back_inserter(tmp),
          [](const Point& a, const Point& b) { return a.y < b.y; });
    copy(tmp.begin(), tmp.end(), pts.begin() + l);
    vector<Point> strip;
    for (int i = l; i < r; ++i)
        if (fabs(pts[i].x - xmid) < d)
            strip.push_back(pts[i]);
    for (int i = 0; i < strip.size(); ++i)
        for (int j = i + 1; j < strip.size() && strip[j].y - strip[i].y < d; ++j)
            d = min(d, dist(strip[i], strip[j]));
    return d;
}

// 用法：
// vector<Point> pts = ...;
// sort(pts.begin(), pts.end());
// double ans = closestPair(pts, 0, pts.size());