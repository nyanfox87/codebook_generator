constexpr ll mxN=1e5+1;
ll n,m,tim=0,id[mxN],sd[mxN],pa[mxN],f[mxN],lb[mxN],et[mxN]{},ret[mxN];
vc<ll> adj[mxN],radj[mxN],t[mxN],st;
void dfs(ll u=1){
	et[u]=++tim,ret[tim]=u;
	id[tim]=sd[tim]=lb[tim]=pa[tim]=tim;
	for(auto&v:adj[u]){
		if(!et[v]) dfs(v),f[et[v]]=et[u];
		radj[et[v]].emp(et[u]);
	}
}
ll find(ll u,ll x=0){
	if(u==pa[u]) return x?-1:u;
	ll v=find(pa[u],x+1);
	if(v<0) return u;
	if(sd[lb[u]]>sd[lb[pa[u]]]) lb[u]=lb[pa[u]];
	pa[u]=v;
	return x?v:lb[u];
}
void built(){
	vc<ll> arr[n+1];
	forr(i,n,1){
		for(auto&v:radj[i]) sd[i]=min(sd[i],sd[find(v)]);
		if(i>1) arr[sd[i]].emp(i);
		for(auto&v:arr[i]){
			ll x=find(v);
			if(sd[x]==sd[v]) id[v]=sd[v];
			else id[v]=x;
		}
		if(i>1) pa[i]=f[i];
	}
	forn(i,2,n+1){
		if(id[i]!=sd[i]) id[i]=id[id[i]];
		t[ret[i]].emp(ret[id[i]]),t[ret[id[i]]].emp(ret[i]);
	}
}
void dfs_ans(ll u=1,ll p=0){
	st.emp(u);
	if(u==n){
		sort(all(st));
		cout << st.size() << '\n';
		for(auto&v:st) cout << v << ' '; cout << '\n';
		exit(0);
	}
	for(auto&v:t[u]){
		if(v==p) continue;
		dfs_ans(v,u);
	}
	st.pop_back();
}
void solve(istream &cin){
	cin>>n>>m;
	forn(i,1,m+1){
		ll u,v; cin>>u>>v;
		adj[u].emp(v);
	}
	dfs();
	built();
	dfs_ans();
}
