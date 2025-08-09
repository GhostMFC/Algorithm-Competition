#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=505;

#define int long long

int n,mod,a[N],cnt;
struct Edge{
	int fo,to,val;
}edge[N*N*2];

inline ll q_Pow(ll A,ll B){
	ll res=1;
	while(B){
		if(B&1) res=res*A%mod;
		B>>=1,A=A*A%mod;
	} return res;
}

int fa[N];
inline int find(int x)
{return x==fa[x]?x:fa[x]=find(fa[x]);}

inline void solve(){
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			edge[++cnt]={i,j,(q_Pow(a[i],a[j])+q_Pow(a[j],a[i]))%mod};
	sort(edge+1,edge+1+cnt,[&](Edge A,Edge B){
		return A.val<B.val;
	});
	
	for(int i=1;i<=n;++i) fa[i]=i;
	
	int tot=1;
	int ans=0;
	while(tot^n){
		int fo=find(edge[cnt].fo),to=find(edge[cnt].to);
		if(fo^to){
			++tot;
			ans+=edge[cnt].val;
			fa[to]=fo;
		}
		--cnt;
	}
	cout<<ans<<'\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>mod;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	solve();
	return 0;
}
