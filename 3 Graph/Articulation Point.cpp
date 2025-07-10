//undirected graph articulation point
ll n,tim=0,art=0;
vc<ll> dfn(mxN,0),low(mxN);
void tarjan(ll u,ll p){
    ll cnt=0;
    dfn[u]=low[u]=++tim;
    for(auto&v:adj[u]){
        if(!dfn[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[v] && u!=root){ //root=dfn[1]
                ++art;
            }
            cnt++;
        }
        else low[u]=min(low[u],dfn[v]);
    }
    if(u==root && cnt>1) art++;
}