constexpr ll mxN=1e5+1;
class state{
    public:
        ll len,link,next[26];
        
        state(){}
};
ll n,sz;
state t[mxN<<1];
void sam(const string &s){
    memset(t,0,sizeof(t));
    t[0].link=-1;
    ll last,cur; last=0;
    for(auto&v:s){
        cur=++sz; 
        t[cur].len=t[last].len+1;
        ll p; p=last;
        while(p!=-1 && !t[p].next[v-'a']) t[p].next[v-'a']=cur,p=t[p].link;
        if(p==-1) t[cur].link=0;
        else{
            ll q; q=t[p].next[v-'a'];
            if(t[p].len+1==t[q].len) t[cur].link=q;
            else{
                ll clone; clone=++sz;
                t[clone].len=t[p].len+1,t[clone].link=t[q].link;
                memcpy(t[clone].next,t[q].next,sizeof(t[q].next));
                while(p!=-1 && t[p].next[v-'a']==q) t[p].next[v-'a']=clone,p=t[p].link;
                t[q].link=t[cur].link=clone;
            }
        }
        last=cur;
    }
}
void solve(istream &cin){
    string s;
    cin>>s;
    n=s.length(),sz=0;
    sam(s);
    vc<ll> res(n+2,0);
    forn(i,1,sz+1) res[t[t[i].link].len+1]++,res[t[i].len+1]--;
    partial_sum(all(res),res.bg());
    forn(i,1,n+1) cout << res[i] << " \n"[i==n];
}
