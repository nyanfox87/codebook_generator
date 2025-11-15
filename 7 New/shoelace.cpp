//consecutive point p[i] (0<=i<n)
//area= p[i].x*p[(i+1)%n].y - p[i].y*p[(i+1)%n].x

void solve(istream &cin){
	ll n,res=0;
	cin>>n;
	forn(i,1,n+1){
		cin>>a[i];
		if(i>1) res+=a[i-1]^a[i];//cross product
		if(i==n) res+=a[n]^a[1];
	}
	cout << abs(res) << '\n';
}
