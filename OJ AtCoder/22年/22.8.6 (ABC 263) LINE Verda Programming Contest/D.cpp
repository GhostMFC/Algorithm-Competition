#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <cmath>
//#include <numeric>
//#include <queue>
//#include <map> //(unordered_map)
//#include <vector>
#define ll long long
#define Mod 998244353
#define ls node[x].lch
#define rs node[x].rch
#define inf 0x7fffffff
#define llinf 0x7fffffffffffffff
//#define F(a,b,c,d) for(int b=c;b<=d;b+=a)
//#define F2(a,b,c,d) for(int b=c;b>=d;b-=a)
using namespace std;
inline ll read(){
	ll xx=0,ff=1; char cc=getchar();
	while(cc>'9'||cc<'0'){ if(cc=='-') ff*=-1; cc=getchar();}
	while(cc<='9'&&cc>='0'){ xx=xx*10+cc-'0'; cc=getchar();}
	return xx*ff;
}
inline ll gcd(ll xx,ll yy){return yy?gcd(yy,xx%yy):xx;}
inline ll q_Mul(ll xx,ll yy,ll pp){ll oo=0; while(yy){ if(yy&1) oo=(oo+xx)%pp; xx=(xx<<1)%pp; yy>>=1;} return oo;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1; while(yy){ if(yy&1) oo=oo*xx%pp; xx=xx*xx%pp; yy>>=1;} return oo;}
//q_Pow can conbine with q_Mul to avoid overflow

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

const int maxn=2e5+5;

ll n,l,r,a[maxn],sum[maxn],dp[maxn];

int main(){//¿¨ÁËÀÏ°ëÌì,md 
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>l>>r; //scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	dp[0]=sum[n];
	ll pos=0,mx1=sum[n];
	for(int i=1;i<=n;++i){
		if(sum[n]-sum[i]+l*i<mx1) mx1=sum[n]-sum[i]+l*i;
		dp[i]=mx1;
	}
	for(int i=n;i>=1;--i){
		ll k=dp[i-1]-sum[n]+sum[i-1]+r*(n-i+1);
		mx1=min(mx1,k);
	}
	cout<<mx1<<'\n';
	return 0;
}

