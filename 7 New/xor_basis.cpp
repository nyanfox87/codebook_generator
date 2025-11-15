constexpr ll mxN=2e5+1;
constexpr ll mxB=31;
ll n,a[mxN],b[mxB]{};
void built(){
	forn(i,1,n+1){
		ll x; x=a[i];
		forr(j,30,0){
			if((x>>j)&1){
				if(!b[j]){b[j]=x; break;}
				else x^=b[j];
			}
		}
	}
}
void solve(istream &cin){
	cin>>n;
	forn(i,1,n+1) cin>>a[i];
	built();
	ll res; res=0;
	forr(i,30,0){
		if(res>>i&1^1) res^=b[i];
	}
	cout << res << '\n';
}
