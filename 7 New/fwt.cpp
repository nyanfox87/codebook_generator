constexpr ll mxB=21;
ll a[1<<mxB]{};
void fwt(ll *arr,ll type){
	for(ll k=2;k<(1<<mxB);k<<=1){
		for(ll i=0,m=k>>1;i+m<(1<<mxB);i+=k){
			forn(j,0,m){
				ll x,y; x=arr[i+j],y=arr[i+j+m];
				arr[i+j]=x+y,arr[i+j+m]=x-y;
				if(type) arr[i+j]/=2,arr[i+j+m]/=2;
			}
		}
	}
}
void solve(istream &cin){
	ll n,pfx,mx;
	cin>>n;
	mx=pfx=0;
	a[0]=1;
	forn(i,0,n){
		ll x; cin>>x;
		pfx^=x,a[pfx]++,mx=max(mx,a[pfx]);
	}
	fwt(a,0);
	forn(i,0,1<<mxB) a[i]=a[i]*a[i];
	fwt(a,1);
	ll res; res=0;
	// forn(i,0,17) cout << a[i] << " \n"[i==16];
	forn(i,0,1<<mxB) res+=(!i?mx>1:a[i]>0);
	cout << res << '\n';
	forn(i,0,1<<mxB) if(!i?mx>1:a[i]) cout << i << ' ';  cout << '\n';
}
 
