struct point
{
	ll x, y;
	point() = default;
	point(ll a, ll b) : x(a), y(b) {}
	friend istream &operator>>(istream &in, point &b) { in >> b.x >> b.y; return in; }
	friend ostream &operator<<(ostream &ou, const point &b) { ou << b.x << " " << b.y; return ou; }
	point operator-(point &b) { return point(x - b.x, y - b.y); }
	inline ll cross(const point &b) { return x * b.y - y * b.x; }
};
 
inline int ll_prot(ll temp) { return temp > 0 ? 1 : temp < 0 ? -1 : 0; }
 
inline bool check_touch(point a, point b, point c, point d)
{
	if (max(a.x, b.x) < min(c.x, d.x)) return false;
	if (max(a.y, b.y) < min(c.y, d.y)) return false;
	if (max(c.x, d.x) < min(a.x, b.x)) return false;
	if (max(c.y, d.y) < min(a.y, b.y)) return false;
	if (ll_prot((a - b).cross(a - c)) * ll_prot((a - b).cross(a - d)) > 0) return false;
	if (ll_prot((c - d).cross(c - b)) * ll_prot((c - d).cross(c - a)) > 0) return false;
	return true;
}