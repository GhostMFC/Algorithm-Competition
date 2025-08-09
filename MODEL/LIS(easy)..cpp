for(int i=1;i<=n;++i){
	int a;
	cin>>a;
	if(a>d[len]) d[++len]=a;
	else{
		int pos=lower_bound(d+1,d+1+len,a)-d;
		d[pos]=a;
	}
}