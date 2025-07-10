struct Point {
    double x, y;
};

double polygonArea(const vector<Point>& poly) {
    double area = 0;
    int n = poly.size();
    for (int i = 0; i < n; ++i) {
        area += poly[i].x * poly[(i + 1) % n].y;
        area -= poly[i].y * poly[(i + 1) % n].x;
    }
    return fabs(area) / 2.0;
}