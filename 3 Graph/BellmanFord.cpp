//SFPA

bool sfpa(){
    vc<ll> vs(n,0);
    queue<ll> q; q.emplace(start);
    while(!q.empty()){
        ll u=q.front(); q.pop(),vs[u]=0;
        for(auto&[v,w]:adj[u]){
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                if(!vs[v]){vs[v]=1,cnt[v]++; if(cnt[v]>n) return false; q.emplace(v);}
            }
        }
    }
    return true;
}