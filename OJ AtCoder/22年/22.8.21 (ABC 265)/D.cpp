#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=2e5+5;

ll s[maxn],a,b,c,n;

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>a>>b>>c;
	b+=a,c+=b;
	int k;
	for(int i=1;i<=n;++i){
		cin>>k;
		s[i]=s[i-1]+k;
	}
	
	for(int i=0;i<=n-3;++i){
		int l=i,r=n-2;
		while(l<r){
			int mid=(l+r)>>1;
			if(s[mid]-s[i]<a) l=mid+1;
			else r=mid;
		} if(s[l]-s[i]!=a) continue;
		
		l=i,r=n-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(s[mid]-s[i]<b) l=mid+1;
			else r=mid;
		} if(s[l]-s[i]!=b) continue;
		
		l=i,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(s[mid]-s[i]<c) l=mid+1;
			else r=mid;
		} if(s[l]-s[i]!=c) continue;
		else{
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
	return 0;
}
