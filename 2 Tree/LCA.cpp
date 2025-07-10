
ll pa[mxN][20],d[mxN]{};
vc<ll> adj[mxN]
void dfs(ll u=1,ll p=0){d[u]=d[p]+1,pa[u][0]=p; for(auto&v:adj[u]) if(v!=p) dfs(v,u);}
ll lca(ll u,ll v){
    if(d[u]<d[v]) swap(u,v); forr(i,20,0) if(d[u]-(1<<i)>=d[v]) u=pa[u][i]; if(u==v) return u;
    forr(i,20,0) if(pa[u][i]!=pa[v][i]) u=pa[u][i],v=pa[v][i]; return pa[u][0];
}

void init(int n) {
	dfs(1, 0, 1);
	for (int j = 1; j < 20; j++) {
		for (int i = 1; i <= n; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}