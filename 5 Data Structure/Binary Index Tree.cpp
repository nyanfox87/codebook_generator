//BIT is always 1 index
ll n,t[mxN],a[mxN];
void built(){forn(i,1,mxN){ t[i]+=a[i]; if(i+(i&-i)<mxN) t[i+(i&-i)]+=t[i];}} //O(n)
void pad(ll p,ll val){for(;p<mxN;t[p]+=val,p+=p&-p);}
ll query(ll p){ll ans=0; for(;p;ans+=t[p],p-=p&-p); return ans;}