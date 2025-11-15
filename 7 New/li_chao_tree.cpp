class line {
	public:
	ll m,c;
	line(){m=0,c=-inf-1;}
	line(ll m,ll c):m(m),c(c){}
	ll cal(ll x){return m*x+c;}
};
constexpr ll mxN=1e5+5;
ll n;
line t[mxN<<2];
void insert(line x,ll l,ll r,ll i,ll sl,ll sr){
	if(sr<l || r<sl || l>r) return;
	ll mid=(sl+sr)>>1;
	if(l<=sl && sr<=r){ //if extended otherwise remove this condtion
		bool lf=t[i].cal(sl-1)<x.cal(sl-1),mf=t[i].cal(mid-1)<x.cal(mid-1),rf=t[i].cal(sr-1)<x.cal(sr-1);
		if(mf) swap(x,t[i]);
		if(sl==sr) return;
		if(lf^mf) insert(x,l,r,i<<1,sl,mid);
		if(rf^mf) insert(x,l,r,i<<1|1,mid+1,sr);
		return;
	}
	insert(x,l,r,i<<1,sl,mid);
	insert(x,l,r,i<<1|1,mid+1,sr);
}
ll query(ll x,ll i,ll sl,ll sr){
	ll mid=(sl+sr)>>1;
	if(sl==sr) return t[i].cal(x-1);
	if(x<=mid) return max(t[i].cal(x-1),query(x,i<<1,sl,mid));
	else return max(t[i].cal(x-1),query(x,i<<1|1,mid+1,sr));
}
void solve(){
	cin >> n;
	forn(i,0,n){
		ll op;
		cin >> op;
		if(op==1){
			ll a,b,l,r;
			cin >> a >> b >> l >> r;
			line x{a,b};
			insert(x,l+1,r+1,1,1,mxN-4);
		}
		else{
			ll x;
			cin >> x;
			x=query(x+1,1,1,mxN-4);
			if(x>-inf-1) cout << x << '\n';
			else cout << "NO" << '\n';
		}
	}
}
