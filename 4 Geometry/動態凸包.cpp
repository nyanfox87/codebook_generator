struct Point {
    long long x, y;
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

long long cross(const Point& a, const Point& b, const Point& c) {
    // 向量ab x bc
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

struct DynamicConvexHull {
    set<Point> up, dn; // 上凸包、下凸包

    void insert(const Point& p) {
        insertHull(up, p, false); // 上凸包
        insertHull(dn, p, true);  // 下凸包
    }

    // 取得逆時針順序的凸包點（不重複端點）
    vector<Point> getConvexHull() const {
        vector<Point> res;
        for (auto p : up) res.push_back(p);
        vector<Point> dnvec(dn.rbegin(), dn.rend());
        for (int i = 1; i + 1 < dnvec.size(); ++i) // 去掉首尾重複
            res.push_back(dnvec[i]);
        return res;
    }

private:
    // flag: false=上凸包, true=下凸包
    void insertHull(set<Point>& hull, const Point& p, bool flag) {
        auto it = hull.insert(p).first;
        // 刪除左側不在凸包上的點
        while (it != hull.begin()) {
            auto prv = prev(it);
            if (prv == hull.begin()) break;
            auto pprv = prev(prv);
            if ((cross(*pprv, *prv, *it) > 0) ^ flag)
                hull.erase(prv);
            else break;
        }
        // 刪除右側不在凸包上的點
        while (next(it) != hull.end()) {
            auto nxt = next(it);
            if (next(nxt) == hull.end()) break;
            auto nnxt = next(nxt);
            if ((cross(*it, *nxt, *nnxt) > 0) ^ flag)
                hull.erase(nxt);
            else break;
        }
    }
};