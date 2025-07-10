
constexpr ll mxN=505;
ll n,m,adj[mxN][mxN]{},g[mxN][mxN]{};//adj=capacity
vc<ll> pa;
ll bfs(){
	queue<pll> q; q.emplace(pll{0,inf});
	while(!q.empty()){
		auto [u,flow]=q.front(); q.pop();
		forn(i,0,n) 
			if(g[u][i] && adj[u][i] && pa[i]==-1){
				pa[i]=u;
				if(i==n-1) return min(flow,adj[u][i]);
				q.emplace(pll{i,min(flow,adj[u][i])});
			}
	}
	return 0;
}
void solve(istream &cin){
	cin>>n>>m;
	pa.resize(n);
	forn(i,1,m+1){ll u,v; cin>>u>>v,u--,v--; adj[u][v]=g[u][v]=1,adj[v][u]=g[v][u]=1;}
	ll f=0;
	fill(all(pa),-1),pa[0]=0;
	for(ll nf;nf=bfs();f+=nf){
		ll cur=n-1;
		while(cur) adj[pa[cur]][cur]-=nf,adj[cur][pa[cur]]+=nf,cur=pa[cur];
		fill(all(pa),-1),pa[0]=0;
	}
	vc<pll> res;
	forn(i,0,n) forn(j,0,n) if(g[i][j] && pa[i]!=-1 && pa[j]==-1) res.emp(pll{i,j});
	cout << res.size() << '\n';
	for(auto&[u,v]:res) cout << u+1 << ' ' << v+1 << '\n';
}
int main()
{
    fast_io;
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
