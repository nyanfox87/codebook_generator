using cp=complex<double>;
const double pi=acos(-1);
constexpr ll mxN=2e5+1;
ll n,m;
vc<cp> a(mxN<<2,{0,0}),b(mxN<<2,{0,0});
void fft(ll sz,vc<cp> &arr,ll inv){
	for(ll i=1,j=0;i<sz;++i){
		ll bit=sz>>1;
		for(;j&bit;j^=bit,bit>>=1); j^=bit;
		if(i<j) swap(arr[i],arr[j]);
	}
	for(ll l=2;l<=sz;l<<=1){
		double ang=2*pi/l*(inv?-1:1);
		cp wlen=cp(cos(ang),sin(ang));
		for(ll i=0;i<sz;i+=l){
			cp w=cp(1,0);
			for(ll j=0;j<l/2;++j){
				cp x=arr[i+j],y=arr[i+j+l/2]*w;
				arr[i+j]=x+y,arr[i+j+l/2]=x-y;
				w*=wlen;
			}
		}
	}
	if(inv) for(auto&v:arr) v/=sz;
}