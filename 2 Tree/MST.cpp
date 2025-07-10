//kruskal
//vertex is 1 index
#define mls multiset

ll n,pa[mxN];//memset(pa,-1,sizeof(pa));
mls<ar<ll,3>> adj;

ll find(ll x){return pa[x]<0?x:pa[x]=find(pa[x]);}
void un(ll x,ll y){
    x=find(x),y=find(y); if(x==y) return;
    if(-pa[x]>-pa[y]) swap(x,y); pa[y]+=pa[x],pa[x]=y;
}
void kruskal(){
    ll cnt=0,wi=0;
    while(!adj.empty() && cnt<n-1){
        auto [w,u,v]=*adj.begin(); adj.erase(adj.begin());
        if(find(u)!=find(v)) wi+=w,un(u,v);
    }
}