int maxManhattanDist(const vector<Point>& pts) {
    int res = 0;
    for (int d = 0; d < 4; ++d) {
        int mn = 1e9, mx = -1e9;
        for (auto p : pts) {
            int val;
            if (d == 0) val = p.x + p.y;
            if (d == 1) val = p.x - p.y;
            if (d == 2) val = -p.x + p.y;
            if (d == 3) val = -p.x - p.y;
            mn = min(mn, val);
            mx = max(mx, val);
        }
        res = max(res, mx - mn);
    }
    return res;
}