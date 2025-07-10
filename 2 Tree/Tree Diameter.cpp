#define emp emplace_back()
ll n,res=0;
vc<ll> adj[mxN],dp(mxN);

void dfs(ll u=1,ll p=0){dp[u]=0; for(auto&v:adj[u]) if(v!=p) dfs(v,u),res=max(res,dp[u]+dp[v]+1),dp[u]=max(dp[u],dp[v]+1);}

int main()
{
    cin>>n; forn(i,0,n-1){ll u,v; cin>>u>>v; adj[u].emp(v),adj[v].emp(u);}
    dfs();
    cout << res << '\n';
}