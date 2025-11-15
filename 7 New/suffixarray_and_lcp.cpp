constexpr ll mxN=1e5+5;
ll sa[mxN],nsa[mxN],c[mxN],nc[mxN],cnt[mxN]{},lcp[mxN];
void sfa(string s){
	s+="$";
	ll n=s.length();
	forn(i,0,n) cnt[s[i]]++; forn(i,1,256) cnt[i]+=cnt[i-1];
	forr(i,n-1,0) sa[--cnt[s[i]]]=i; c[sa[0]]=0; forn(i,1,n) c[sa[i]]=c[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
	for(ll h=0;(1<<h)<n;h++){
		forn(i,0,n) nsa[i]=((sa[i]-(1<<h))%n+n)%n;
		fill(cnt,cnt+c[sa[n-1]]+1,0);
		forn(i,0,n) cnt[c[nsa[i]]]++; forn(i,1,c[sa[n-1]]+1) cnt[i]+=cnt[i-1];
		forr(i,n-1,0) sa[--cnt[c[nsa[i]]]]=nsa[i];
		nc[sa[0]]=0;
		forn(i,1,n){
			pll pre={c[sa[i-1]],c[(sa[i-1]+(1<<h))%n]},cur={c[sa[i]],c[(sa[i]+(1<<h))%n]};
			nc[sa[i]]=nc[sa[i-1]]+(cur!=pre);
		}
		swap(c,nc);
	}
}
void Lcp(const string &s){
	ll n=s.length(),k=0;
	forn(i,0,n){
		if(c[i]>n-1){k=0; continue;}
		ll j=sa[c[i]+1];
		for(;i+k<n && j+k<n && s[i+k]==s[j+k];k++);
		lcp[c[i]]=k;
		if(k) k--;
	}
}
