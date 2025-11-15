constexpr ll mxN=1e5+1;
constexpr ll mxB=20;
ll n,m,q,st[mxN],id=0,mark[mxN]{},dfn[mxN]{},low[mxN],tim=0,nid[mxN],pa[mxN<<1][mxB],d[mxN<<1];
vc<ll> adj[mxN];
vc<vc<ll>> cmp,t;
void tarjan(ll u=1,ll p=0){
	dfn[u]=low[u]=++tim,st[++id]=u;
	for(auto&v:adj[u]){
		if(v==p) continue;
		if(dfn[v]) low[u]=min(low[u],dfn[v]);
		else{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				mark[u]=(dfn[u]>1 || dfn[v]>2);
				cmp.emp(vc<ll>{u});
				while(cmp.back().back()!=v) cmp.back().emp(st[id--]);
			}
		}
	}
}
void dfs(ll u=1,ll p=0,ll lv=1){
	d[u]=lv,pa[u][0]=p;
	for(auto&v:t[u]){
		if(v!=p) dfs(v,u,lv+1);
	}
}
void built(){
	ll x=0;
	t.emp(vc<ll>{});
	forn(i,1,n+1) if(mark[i]) nid[i]=++x,t.emp(vc<ll>{});
	for(auto&a:cmp){
		ll y=++x;
		t.emp(vc<ll>{});
		for(auto&u:a){
			if(mark[u]) t[nid[u]].emp(y),t[y].emp(nid[u]);
			else nid[u]=y;
		}
	}
	err(t.size());
	dfs();
	forn(j,1,mxB) forn(i,1,t.size()) pa[i][j]=pa[pa[i][j-1]][j-1];
}
ll lca(ll a,ll b){
	if(d[a]<d[b]) swap(a,b);
	forr(i,mxB-1,0) if(d[a]-(1<<i)>=d[b]) a=pa[a][i];
	if(a==b) return a;
	forr(i,mxB-1,0) if(pa[a][i]!=pa[b][i]) a=pa[a][i],b=pa[b][i];
	return pa[a][0];
}
ll query(ll a,ll b,ll c){
	ll lca1=lca(a,b),lca2=lca(a,c),lca3=lca(b,c);
	return (lca1==c || (lca2==c && lca3==lca1) || (lca3==c && lca2==lca1));
}
void solve(){
	cin >> n >> m >> q;
	forn(i,0,m){
		ll u,v; cin >> u >> v;
		adj[u].emp(v),adj[v].emp(u);
	}
	tarjan();
	built();
	while(q--){
		ll a,b,c; cin >> a >> b >> c;
		cout << ((mark[c] && query(nid[a],nid[b],nid[c])) || a==c || b==c?"NO":"YES") << '\n';
	}
}
