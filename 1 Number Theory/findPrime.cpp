mobius[1]=1;
forn(i,2,mxN){
	if(!prime[i]) prime[i]=i,mobius[i]=-1,etf[i]=i-1,st[++sz]=i;
	forn(j,1,sz+1){
		if(i*st[j]>=mxN) break; 
		prime[i*st[j]]=st[j]; 
		if(i%st[j]==0){
			mobius[i*st[j]]=0;
			etf[i*st[j]]=etf[i]*st[j];
			break;
		}
		else mobius[i*st[j]]=mobius[i]*-1,etf[i*st[j]]=etf[i]*(st[j]-1);
	}
}
