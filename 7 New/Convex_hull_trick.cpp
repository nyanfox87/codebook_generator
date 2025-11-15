class line{
	public:
		ll m,c;
		line(){}
		line(ll m,ll c):m(m),c(c){}
		friend bool operator<(const line &a,const line &b){
			return a.m<b.m || (a.m==b.m && a.c>b.c);
		}
		ll cal(ll x){return m*x+c;}
};
constexpr ll mxN=1e5+1;
ll n,m,id=0,st[mxN];
vc<line> ln;
bool check(ll i,ll j,ll k){
	return (ln[i].c-ln[k].c)*(ln[j].m-ln[i].m)<(ln[i].c-ln[j].c)*(ln[k].m-ln[i].m);
}
void solve(istream &cin){
	cin >> n >> m;
	forn(i,0,n){
		ll y1,y2; cin >> y1 >> y2;
		ln.emp(line{(y2-y1)/m,y1});
	}
	sort(all(ln)),ln.resize(unique(all(ln),[](auto a,auto b){return a.m==b.m;})-ln.bg());
	forn(i,0,ln.size()){
		while(id>1 && check(st[id-1],st[id],i)) id--;
		st[++id]=i;
	}
	ll ptr=1;
	forn(i,0,m+1){
		while(ptr+1<=id && ln[st[ptr+1]].cal(i)>ln[st[ptr]].cal(i)) ptr++;
		cout << ln[st[ptr]].cal(i) << " \n"[i==m];
	}
}
