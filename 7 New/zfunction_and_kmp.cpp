constexpr ll mxN=1e6+1;
vc<ll> zf(const string &s){
	ll n,l,r; n=s.length(),l=r=-1;
	vc<ll> z(n,0);
	forn(i,1,n){
		if(r>i) z[i]=min(z[i-l],r-i);
		while(i+z[i]<n && s[i+z[i]]==s[z[i]]) z[i]++;
		if(i+z[i]>r) r=i+z[i],l=i;
	}
	return z;
}
vc<ll> kmp(const string &s){
	ll n; n=s.length();
	vc<ll> k(n,0);
	forn(i,1,n){
		ll j; j=k[i-1];
		while(j>0 && s[i]!=s[j]) j=k[j-1];
		if(s[i]==s[j]) k[i]=j+1;
	}
	return k;
}
