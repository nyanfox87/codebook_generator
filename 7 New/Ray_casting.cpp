class Point{
	public:
		ll x,y;
		Point(){}
		Point(ll x,ll y):x(x),y(y){}
		friend Point operator-(const Point &a,const Point &b){return {a.x-b.x,a.y-b.y};}
		friend ll operator*(const Point &a,const Point &b){return a.x*b.x+a.y*b.y;}
		friend ll operator^(const Point &a,const Point &b){return a.x*b.y-a.y*b.x;}
};
ll n,m;
vc<Point> p;
bool on(Point &a,Point &b,Point &c){
	if((b-a)^(c-a)) return false;
	return 0<=((b-a)*(c-a)) && ((b-a)*(c-a))<=((b-a)*(b-a));
}
void query(Point &x){
	ll ok=0;
	forn(i,0,n){
		if(on(p[i],p[(i+1)%n],x)){ cout << "BOUNDARY" << '\n';return;}
		Point &a=p[i],&b=p[(i+1)%n];
		if(a.y>x.y != b.y>x.y){
			ll sg=(x-a)^(b-a);
			if(b.y>a.y==(sg<0)) ok^=1;
		}
	}
	cout << (ok&1?"INSIDE":"OUTSIDE") << '\n';
}
