#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll cross(P a, P b) { return a.first * b.second - a.second * b.first; }
ll dist2(P a, P b) {
    ll dx = a.first - b.first, dy = a.second - b.second;
    return dx * dx + dy * dy;
}
double dist(P a, P b) { return sqrt(dist2(a, b)); }

// Andrew's Monotone Chain
vector<P> convex_hull(vector<P> pts) {
    sort(pts.begin(), pts.end());
    int n = pts.size(), k = 0;
    vector<P> hull(2 * n);
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross({hull[k-1].first-hull[k-2].first, hull[k-1].second-hull[k-2].second},
                               {pts[i].first-hull[k-1].first, pts[i].second-hull[k-1].second}) <= 0)
            --k;
        hull[k++] = pts[i];
    }
    for (int i = n-2, t = k; i >= 0; --i) {
        while (k > t && cross({hull[k-1].first-hull[k-2].first, hull[k-1].second-hull[k-2].second},
                              {pts[i].first-hull[k-1].first, pts[i].second-hull[k-1].second}) <= 0)
            --k;
        hull[k++] = pts[i];
    }
    hull.resize(k-1);
    return hull;
}

double circumradius(P a, P b, P c) {
    double A = dist(b, c), B = dist(a, c), C = dist(a, b);
    double S = abs(cross({b.first-a.first, b.second-a.second},
                         {c.first-a.first, c.second-a.second})) / 2.0;
    if (S == 0) return 0; // 共線
    return (A * B * C) / (4.0 * S);
}

int main() {
    int n;
    cin >> n;
    vector<P> pts(n);
    for (int i = 0; i < n; ++i) cin >> pts[i].first >> pts[i].second;
    vector<P> hull = convex_hull(pts);
    int m = hull.size();
    double ans = 0;
    // 旋轉卡殼
    for (int i = 0; i < m; ++i) {
        int j = (i + 1) % m, k = (j + 1) % m;
        do {
            while (true) {
                int k2 = (k + 1) % m;
                double r1 = circumradius(hull[i], hull[j], hull[k]);
                double r2 = circumradius(hull[i], hull[j], hull[k2]);
                if (r2 > r1) k = k2;
                else break;
            }
            ans = max(ans, circumradius(hull[i], hull[j], hull[k]));
            j = (j + 1) % m;
        } while (j != i);
    }
    cout << fixed << setprecision(6) << ans << endl;
}