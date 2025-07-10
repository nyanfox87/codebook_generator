
constexpr ll mxN=505;
class fe{
	public:
		ll u,v,cp,fw;
		fe(){}
		fe(ll U,ll V,ll CP):u(U),v(V),cp(CP){fw=0;}
};
ll n,m,sz=0;
vc<fe> edg;
queue<ll> q;
vc<ll> adj[mxN],ptr,dep;
bool bfs(){
	while(!q.empty()){
		ll u=q.front(); q.pop();
		for(auto&id:adj[u]){
			if(edg[id].cp==edg[id].fw || dep[edg[id].v]!=-1) continue;
			dep[edg[id].v]=dep[u]+1,q.emplace(edg[id].v);
		}
	}
	return dep[n-1]!=-1;
}
ll dinic(ll u,ll push){
	if(!push) return 0;
	if(u==n-1) return push;
	for(ll &cid=ptr[u];cid<adj[u].size();++cid){
		ll id=adj[u][cid];
		ll v=edg[id].v;
		if(dep[v]!=dep[u]+1) continue;
		ll tr=dinic(v,min(push,edg[id].cp-edg[id].fw));
		if(!tr) continue;
		edg[id].fw+=tr,edg[id^1].fw-=tr;
		return tr;
	}
	return 0;
}
void solve(istream &cin){
	cin>>n>>m;
	ptr.resize(n),dep.resize(n);
	forn(i,1,m+1){
		ll u,v,c; cin>>u>>v>>c,u--,v--;
		edg.emp(fe{u,v,c}),edg.emp(fe{v,u,0});
		adj[u].emp(sz),adj[v].emp(sz+1),sz+=2;
	}
	ll res=0;
	for(;;){
		ll flow;
		fill(all(dep),-1);
		q.emplace(0),dep[0]=0;
		if(!bfs()) break;
		fill(all(ptr),0);
		for(;flow=dinic(0,inf);res+=flow);
	}
	cout << res << '\n';
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
