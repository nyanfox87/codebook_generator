class FFT{
	public:
		ll mod,root,root_inv,maX,M,M_inv;
		FFT(){}
		FFT(ll a,ll b,ll c,ll d,ll e,ll f):mod(a),root(b),root_inv(c),maX(d),M(e),M_inv(f){}
		ll fsp(ll a,ll m){
			ll ans=1;
			while(m){
				if(m&1) ans=(ans*a)%mod;
				a=(a*a)%mod,m>>=1;
			}
			return ans;
		}
		void fft(ll sz,vc<ll> &arr,ll inv){
			for(ll i=1,j=0;i<sz;++i){
				ll bit=sz>>1; for(;j&bit;bit>>=1) j^=bit; j^=bit;
				if(i<j) swap(arr[i],arr[j]);
			}
			for(ll l=2;l<=sz;l<<=1){
				ll wlen=inv?root_inv:root;
				for(ll i=l;i<maX;i<<=1) wlen=(wlen*wlen)%mod;
				for(ll i=0;i<sz;i+=l){
					ll w=1;
					for(ll j=0;j<l/2;++j){
						ll x=arr[i+j],y=(w*arr[i+j+l/2])%mod;
						arr[i+j]=(x+y<mod?x+y:x+y-mod);
						arr[i+j+l/2]=(x-y>=0?x-y:x-y+mod);
						w=(w*wlen)%mod;
					}
				}
			}
			if(inv){
				ll n_1=fsp(sz,mod-2);
				forn(i,0,sz){
					arr[i]=(arr[i]*n_1)%mod;
				}
			}
		}
};
constexpr ll MM=1002772198720536577;
//
//g=3
//998244353=119*2^23 + 1 
//g^c=15311432
//inv=469870224
//M1=1004535809
//M1^-1=332747959
//
//1004535809=479*2^21 + 1
//g^c=702606812
//inv=700146880
//M2=998244353
//M2^-1=669690699
ll mul(ll a,ll b){
	__int128 aa=a,bb=b,cc;
	cc=(aa*bb)%MM;
	return (ll)cc;
}
void solve(){
	FFT fft1(998244353,15311432,469870224,1<<23,1004535809,332747959);
	FFT fft2(1004535809,702606812,700146880,1<<21,998244353,669690699);
	//ll x=(fft1.M*fft1.M_inv)%fft1.mod;
	//ll y=(fft2.M*fft2.M_inv)%fft2.mod;
	//err(x,y);
	ll n,m;
	cin >> n >> m;
	vc<ll> a(n+1),b(m+1);
	for(auto &v:a) cin >> v;
	for(auto &v:b) cin >> v;
	ll sz=1;
	for(;sz<a.size()+b.size();sz<<=1);
	a.resize(sz),b.resize(sz);
	vc<ll> A=a,B=b;
	fft1.fft(sz,a,0);
	fft1.fft(sz,b,0);
	forn(i,0,sz) a[i]=(a[i]*b[i])%fft1.mod;
	fft1.fft(sz,a,1);

	fft2.fft(sz,A,0);
	fft2.fft(sz,B,0);
	forn(i,0,sz) A[i]=(A[i]*B[i])%fft2.mod;
	fft2.fft(sz,A,1);

	forn(i,0,n+m+1) cout << (mul(a[i],fft1.M*fft1.M_inv) + mul(A[i],fft2.M*fft2.M_inv))%MM << " \n"[i==n+m];
}
