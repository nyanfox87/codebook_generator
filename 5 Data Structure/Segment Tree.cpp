//range add range query // sum query
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define forn(a,b,c) for(ll a=b;a<c;++a)
constexpr ll mxN=2e5+1;
#pragma GCC target("lzcnt")
ll n,q,t[mxN<<1],lz[mxN]{};
void built(){forr(i,n-1,1)t[i]=t[i<<1]+t[i<<1|1];}
void apply(ll p,ll k,ll val){t[p]+=val*k; if(p<n) lz[p]+=val;}
void push(ll p){for(ll h=63-__builtin_clzll(p);h;h--) if(lz[p>>h]){apply((p>>h)<<1,1<<(h-1),lz[p>>h]),apply((p>>h)<<1|1,1<<(h-1),lz[p>>h]),lz[p>>h]=0;}}
void built(ll p){for(;p>>=1;)if(!lz[p]) t[p]=t[p<<1]+t[p<<1|1];}
void rad(ll l,ll r,ll val){
    ll l0=l+=n-1,r0=r+=n-1,k=1; push(l0),push(r0);
    for(;l<=r;l>>=1,r>>=1,k<<=1){if(l&1) apply(l++,k,val); if(r&1^1) apply(r--,k,val);}
    built(l0),built(r0);
}
ll query(ll l,ll r){ ll ans=0; push(l+=n-1),push(r+=n-1); for(;l<=r;l>>=1,r>>=1){if(l&1) ans+=t[l++]; if(r&1^1) ans+=t[r--];} return ans;} //range query
ll query(ll p){push(p+=n-1); return t[p];} // point query
